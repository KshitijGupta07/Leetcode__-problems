class Solution {
public:
   bool check(int k,int i,int j,vector<vector<char>>&board){
        for(int x=0;x<9;x++){
            if(board[x][j]-'0'==k&&x!=i){
                return false;
            }
        }
        for(int x=0;x<9;x++){
            if(board[i][x]-'0'==k&&x!=j){
                return false;
            }
        }
        int rmin=i-i%3;
        int rmax=i+(2-i%3);
        int cmin=j-j%3;
        int cmax=j+(2-j%3);
        for(int x=rmin;x<=rmax;x++){
            for(int y=cmin;y<=cmax;y++){
                if(board[x][y]-'0'==k){
                    if(x!=i||y!=j){
                        return false;
                    }
                }
            }
        }
        return true;
   }
    bool solve(vector<vector<char>>&board){
          for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                  if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(check(k,i,j,board)){
                            board[i][j]=k+'0';
                            if(solve(board)==true){
                                return true;
                            }
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