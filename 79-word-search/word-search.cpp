class Solution {
public:
     bool solve(vector<vector<char>>& board, string word,int i,int j,int index){
         if(index>=word.length())return true;
        if(i>=board.size()||i<0||j>=board[0].size()||j<0||board[i][j]=='.')return false;
       
        bool left=false;
        bool right=false;
        bool up=false;
        bool down=false;
        if(board[i][j]==word[index]){
            board[i][j]='.';
            left=solve(board,word,i-1,j,index+1);
            right=solve(board,word,i+1,j,index+1);
            up=solve(board,word,i,j-1,index+1);
            down=solve(board,word,i,j+1,index+1);
            board[i][j]=word[index];

        }
        else{
        return false;
        }
        return left||right||up||down;
    
     }
    bool exist(vector<vector<char>>& board, string word) {
        int n=word.length();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    
                    if(solve(board,word,i,j,0))return true;
                    
                }
            }
        }
        return false;
    }
};