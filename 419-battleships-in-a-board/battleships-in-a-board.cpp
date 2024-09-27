class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
         int count=0;
        
         for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(i==0){
                    if(j==0&&board[i][j]=='X'){
                        count++;
                    }
                    if(j>0&&board[i][j]=='X'&&board[i][j-1]=='.'){
                        count++;
                    }
                }
                else{
                    if(j==0&&board[i][j]=='X'&&board[i-1][j]=='.'){
                        count++;

                    }
                    if(j>0&&board[i][j]=='X'&&board[i-1][j]=='.'&&board[i][j-1]=='.'){
                        count++;
                    }
                }
            
         }
         }
         
         return count;
    }
};