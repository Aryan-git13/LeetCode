class Solution {
public:
    // bool solve(vector<vector<char>>& board){
    //     for(int i=0;i<board.size();i++){
    //         for(int j=0;j<board[0].size();j++){
    //             if(board[i][j]=='.'){
    //                 for(char ch='1';ch<='9';ch++){
    //                     if(isValid(board,i,j,ch)){
    //                         board[i][j]=ch;

    //                         if(solve(board)==true)return true;
    //                         else board[i][j]='.';
    //                     }
    //                 }
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    bool isValid(vector<vector<char>>& board,int i,int j,char ch){
        for(int k=0;k<9;k++){
            if(k!=i && board[k][j]==ch)return false;
            if(k!=j && board[i][k]==ch)return false;

            // adding the special note to this because it is the important concept remeber how to appy it 
            int r=3*(i/3)+k/3;
            int c=3*(j/3)+k%3;

            if((r!=i or c!=j ) && board[r][c]==ch)return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
       for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]!='.'){
                if(isValid(board,i,j,board[i][j])==false)return false;
            }
        }
       }
       return true;
    }
};