class Solution {
public:
    bool isValid(int i,int j,vector<vector<char>>& board,char ch ){
        for(int k=0;k<9;k++){
            if(board[k][j]==ch)return false;
            if(board[i][k]==ch)return false;

            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==ch)return false ;
        }
        // board[i][j]=ch;
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isValid(i,j,board,ch)){board[i][j]=ch;
                        if(solve(board))return true;
                         board[i][j]='.';
                         }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};