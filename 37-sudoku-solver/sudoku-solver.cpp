class Solution {
public:
   bool check(int i,int j,char ch,vector<vector<char>>&board){
        for(int x=0;x<board.size();x++){
              if(board[i][x]==ch&&x!=j){
                return false;
              }
        }
        for(int x=0;x<board.size();x++){
            if(board[x][j]==ch&&x!=i){
                return false;
            }
        }
        int mod=i%3;
        int mod2=j%3;
        int row1=i-mod;
        int row2=i+(2-mod);
        int col1=j-mod2;
        int col2=j+(2-mod2);
        for(int x=row1;x<=row2;x++){
            for(int y=col1;y<=col2;y++){
                if(board[x][y]==ch){
                    if(x==i&&y==j){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;

   }
    bool  solve(vector<vector<char>>&board){
         for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                 if(board[i][j]=='.'){
                    for(int x=1;x<=9;x++){
                        
                        if(check(i,j,x+'0',board)){
                            board[i][j]=x+'0';
                            if(solve(board)){
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