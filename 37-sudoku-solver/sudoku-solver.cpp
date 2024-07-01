class Solution {
public:
 bool issafe(vector<vector<char>>& board,int row,int col,int val){
    for(int i=0;i<board.size();i++){
        if(board[row][i]==val+'0'){
            return false;
        }
        if(board[i][col]==val+'0'){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val+'0'){
            return false;
        }
    }
    return true;
 }
  bool solve(vector<vector<char>>& board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){

            //traversing element
            if(board[i][j]=='.'){
                //if we see empty place 
                for(int val=1;val<=9;val++){
                    //chceking value
                    if(issafe(board,i,j,val)){
                        board[i][j]=val+'0';
                        bool solution=solve(board);
                        if(solution){
                            return true;
                        }
                        else{
                        board[i][j]='.';
                        }
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