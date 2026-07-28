class Solution(object):
    def isValid(self,board,i,j,ch):
        for k in range(9):
            if k!=i and board[k][j]==ch:
                return False
            if k!=j and board[i][k]==ch:
                return False

            r=3*(i//3)+k//3
            c=3*(j//3)+k%3

            if(r!=i or c!=j) and board[r][c]==ch:
                return False

        return True

    def isValidSudoku(self, board):
       for i in range(9):
        for j in range(9):
            if board[i][j]!=".":
                    if not self.isValid(board,i,j,board[i][j]):
                        return False

       return True 

        