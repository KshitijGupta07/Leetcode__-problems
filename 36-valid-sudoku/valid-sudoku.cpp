class Solution {
public:
   bool isSafe(int& row,int& col,vector<vector<char>>& board,char ch){
    for(int i=0;i<board.size();i++){
        if(board[row][i]==ch&&i!=col){
            cout<<"first"<<endl;
            return false;
        }
        if(board[i][col]==ch&&i!=row){
            
            return false;
        }
        int a=3*(row/3)+i/3;
        int b=3*(col/3)+i%3;
        if(board[a][b]==ch){
            if(a!=row&&b!=col){
                return false;
            }
            
            
        }
    }
    return true;
   }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                if(isSafe(i,j,board,board[i][j])==false){
                    return false;
                }
                }
            }
        }
        return true;
    }
};