def minFlow_bfs(graph, start_node, goal_node):
    visited_nodes = []
    queue = [[start_node]]

    if start_node == goal_node:
        return

    while queue:
        path_travelled = queue.pop(0)
        current_node = path_travelled[-1]

        if current_node not in visited_nodes:
            neighbour_nodes = graph[current_node]
            for k in neighbour_nodes:
                latest_path = list(path_travelled)
                latest_path.append(k)
                queue.append(latest_path)
 
                if k == goal_node:
                    return latest_path
            visited_nodes.append(current_node)

    return
 
if __name__=='__main__':
    graph=dict()
    k=int(input())
    nodes=[0]*k
    for i in range(k):
        nodes[i]=input()
        graph[nodes[i]]=[]
    new_edge=int(input())
    for i in range(new_edge):
        l=input().split()
        graph[l[0]].append(l[1])
    x=input()
    y=input()
    answer_set=set()
    selected_path=minFlow_bfs(graph, x, y)
    while(selected_path!=None):
        answer_set.add(int(selected_path[-2]))
        graph[selected_path[-2]].remove(y)
        selected_path=minFlow_bfs(graph, x, y)
    for i in answer_set:
        print(i,end=' ')
