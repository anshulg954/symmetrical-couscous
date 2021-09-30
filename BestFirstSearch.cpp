#include <iostream>
#include <queue>
#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int vertex;
  	int heuristic; // Estimate to goal
    // this is used to initialize the variables of the class
    node(int vert, int h_value)
        :vertex(vert),heuristic(h_value)//constructor function hai to initialize the values when node variable will be declared
    {
    }
};
// we are doing operator overloading through this
bool operator<(const node& n1, const node& n2)
{
    //direct comparison of h value
    // this will return true when second person has smaller heuristic. Suppose we have //n1.heuristic=5 and n2.heuristic=5.5 then the object which have least heuristic will be at the //top(or max priority)
    return n1.heuristic > n2.heuristic;
}
struct data //normal variables ke liye banaya hai structure
{
	int vertex;
	int heuristic;
	struct data* next;
};

int main()
{
  	int size; //total count of vertices
  	cout<<"Enter Total Number of vertices: ";
	cin>>size;
	struct data* nodes[size+1];//array of pointers, jo 18 nodes hain use store krta hai
	for(int i=0; i<=size; i++ )
	{
		nodes[i]=new data;// new is data allocation
	}
	int a, h, b, start, z; //a-number of neighbor nodes,
  	bool visited[size+1];//to chek if a node is visited or not
	memset(visited, 0, sizeof(visited));// visite darray mei sabme 0 value aa jaega garbage value hatane ke liuye
	for(int i=1; i<=size; i++)
	{
		//Adding elements of graph
		cout<<"Enter the heuristic value and the number of neighbours of node "<<i<<": (heuristic, number of neighbours) "<<endl;
		cin>>h>>a;
		//normal array formed
		struct data *temp=nodes[i];
		temp->heuristic=h;
		temp->vertex=i;
		cout<<"Enter neighbour number and corresponding heuristic of node neighbouring to "<<i<<endl;
		for(int j=0; j<a; j++)
		{
		    //link list formed
			temp->next=new struct data();
			temp=temp->next; //nodes linking ho rhi hai
			cout<<"Enter details of neighbour "<<j+1<<endl;
			cin>>b>>h;
			temp->heuristic=h;
			temp->vertex=b;
		}
		temp->next=NULL;
	}
	cout<<"\nThe Matrix is: (heuristic, number of nodes connected)\n";
	for(int i=1; i<=size; i++)
	{
		struct data *temp = nodes[i];
		cout<<"  "<<temp->vertex<<"("<<temp->heuristic<<") \n";
		bool flag=false;
		while(temp)
		{
			if(flag)
				cout<<"\t---> "<<temp->vertex<<" ("<<temp->heuristic<<") \n";
			temp=temp->next;
			flag=true;
		}
		cout<<endl;
	}
	cout<<"\nThe traversal is \n";
    priority_queue <node> Q;//created a priority queue of type node
  	int top;// priority queue ke top pe
  	struct data *temp = nodes[1];//another pointer to array
	Q.push(node(temp->vertex, temp->heuristic));
	visited[temp->vertex]=true;//node 1 is traversed
 	priority_queue <node> S;
	node x= Q.top();
	cout <<"\t"<< x.vertex << "  (" << x.heuristic<<") ---> " << "\n";
	do
	{
		// To enter the details of the sub nodes
		while(temp)
		{
		    cout<<"HELLO"<<temp->vertex;
			if(!visited[temp->vertex])
				{
					Q.push(node(temp->vertex, temp->heuristic));
					visited[temp->vertex]= true;
				}
			temp=temp->next;
		}
		// To compare the new data nodes with the already
		// existing nodes in the pQ,
		// we first add the new adding nodes in a Queue (Q)
		// then add to this queue the already existing nodes of pQ (T)
		// i.e. copy nodes of T to Q
		// then at lastly sort all the elements of Q and placed orderly in T.
		while(!S.empty())
		{
			node n = S.top();
			Q.push(node(n.vertex, n.heuristic));
			S.pop();
		}
		while(!Q.empty())
		{
			node n = Q.top();
			S.push(node(n.vertex, n.heuristic));
			Q.pop();
		}
		// T.top() refers to the node with the least heuristic value.
		x = S.top();
		top=x.vertex;
		temp=nodes[top];
		cout <<"\t"<< x.vertex << "  (" << x.heuristic<<") --> " << "\n";
		S.pop();
	}while(!S.empty() && x.heuristic!=0);
	// repeat until the GOAL state i.e. heuristic=0 is reached or
	// the desired node is not available, in that case T would be empty.
    return 0;
}
