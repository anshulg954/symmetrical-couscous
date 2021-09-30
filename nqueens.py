import platform
from datetime import datetime
class Queen:
    #INITIALIZE CHESS BOARD WITH A SIZE AS OF THE INPUT
    def __init__(self, matrix_size):
        self.matrix = matrix_size
        #SAY IF COLUMNS[R] = C, THEN C REPRESENT THE COLUMN OF THAT ROW.
        self.columns = []
    #ADD QUEEN TO NEXT ROW
    def next_row(self, column):
        self.columns.append(column)

    #REMOVE QUEEN (TO BE USED DURING BACKTRACKING)
    def remove_present(self):
        return self.columns.pop()
    #CHECK FOR THE SAFE POSITION IN THE NEXT ROW
    def is_safe(self, column):
        row = len(self.columns) #GIVES THE INDEX OF NEXT ROW
        #CHECK WHETHER THE QUEEN IS IN THE SAME COLUMN CORRESPONDING TO THE ONE IN PREVIOUS ROW
        for queen_column in self.columns:
            if column == queen_column:
                return False
        #CHECK WHETHER THERE THE QUEEN IS AT DIAGNOL CORRESPONDING TO THE ONE IN PREVIOUS ROW
        for queen_row, queen_column in enumerate(self.columns):
            if queen_column - queen_row == column - row or ((self.matrix - queen_column) - queen_row == (self.matrix - column) - row) :
                return False
        return True
    #DISPLAY THE CHESS BOARD
    def show(self):
        for row in range(self.matrix):
            for column in range(self.matrix):
                if column == self.columns[row]:
                    print('Q', end=' ')
                else:
                    print('x', end=' ')
            print()

#PERFORM N_QUEEN ON THE INPUT SIZE OF MATRIX
def n_queen(matrix_size):
    chess_board = Queen(matrix_size) #INITIALIZE THE CHESS BOARD
    sol = 0 #NO.OF SOLUTIONS
    row = 0
    column = 0
    while True:
        #UNTIL WE HAVE BEEN THROUGH ALL THE COLUMNS
        while column < matrix_size:
            if chess_board.is_safe(column):#CHECK IF FOR THAT PARTICULAR POSITION IN CHECKBOARD IT IS SAFE TO PLACE OR NOT
                chess_board.next_row(column) #IF YES APPEND THE ROW TO LIST OF COLUMNS[]
                row += 1 #INCREMENT THE ROW AS NEXT QUEEN CANNOT BE PLACED IN THE SAME ROW
                column = 0 #AGAIN INITIALIZE THE COLUMN TO ZERO SO AS TO CHECK FOR THE NEXT WHOLE ROW
                break
            else: #IF THE POSITION IS NOT SAFE INCREMENT THE COLUMN COUNT AND CHECK FOR THE NEXT COLUMN
                column += 1

        if (column == matrix_size or row == matrix_size): #AFTER COLUMN IS UNAVAILABLE TO BE FILLED
            #IF CHESS BOARD IS FILLED
            if row == matrix_size:
                #DISPLAY THE SOLUTION
                chess_board.show()
                print()
                #INCREMENT SOLUTION COUNT
                sol += 1

            #BACKTRACK IF CHESS BOARD IS NOT FILLED AND THE PREVIOUS CONDITION IS TRUE
            try:
                #REMOVE THE LAST FILLED QUEEN
                prev = chess_board.remove_present()
            except IndexError:
                #INCASE OF AN EMPTY LIST INDEX ERROR WILL BE RAISED THEN BREAK
                break

            #SET VALUES FOR NEXT ITERATION TO TRY COLUMN VALUES ABOVE THE COLUMN VALUES OF THE QUEEN JUST REMOVED
            #TRY PREVIOUS ROW AGAIN
            row -= 1
            #CHECK SAME FOR COLUMN = (1 + VALUE OF COLUMN IN PREVIOUS ROW)
            column = 1 + prev

    print('No. of solutions are: {0}'.format(sol))


size = int(input('Enter the size of chess board n: '))
time1= datetime.now()
n_queen(size)
time2 = datetime.now()
print('Time taken for nqueen: ', time2-time1)
print()
print('System Configuration is:')
print(platform.uname())
