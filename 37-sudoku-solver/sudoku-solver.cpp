class Solution {
public:
    bool safe(int i,int j,char ch,vector<vector<char>>&board){
        for(int x=0;x<9;x++){
              if(board[i][x]==ch&&x!=j){
                return false;
              }
        }
        for(int x=0;x<9;x++){
            if(board[x][j]==ch&&x!=i){
                return false;
            }
        }
        for(int x=i-i%3;x<=i+(2-i%3);x++){
            for(int y=j-j%3;y<=j+(2-j%3);y++){
                   if(board[x][y]==ch&&(x!=i||y!=j)){
                       return false;
                   }
            }
        }
        return true;
    }
    bool check(vector<vector<char>>&board){
             for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.'){
                for(int k=1;k<=9;k++){
                
                    if(safe(i,j,k+'0',board)){
                        board[i][j]=k+'0';
                        if(check(board)){
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
          check(board);
    }
};