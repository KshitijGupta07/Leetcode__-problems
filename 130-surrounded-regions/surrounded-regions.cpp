class Solution {
public:
    void solve(vector<vector<char>>& board) {
         queue<pair<int,int>>q;
         vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
          map<pair<int,int>,bool>m;
         for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(i==0||i==board.size()-1||j==0||j==board[0].size()-1){
                    if(board[i][j]=='O'){
                        visited[i][j]=true;
                        m[{i,j}]=true;
                        q.push({i,j});
                    }
                }
            }
         }
         vector<int>a{1,-1,0,0};
         vector<int>b{0,0,-1,1};
        
         while(q.empty()==false){
            pair<int,int>front=q.front();
            q.pop();
            int x=front.first;
            int y=front.second;
            for(int i=0;i<4;i++){
                int newx=x+a[i];
                int newy=y+b[i];
                if(newx>=0&&newy>=0&&newx<board.size()&&newy<board[0].size()&&visited[newx][newy]==false){
                       if(board[newx][newy]=='O'){
                        visited[newx][newy]=true;
                          m[{newx,newy}]=true;
                          q.push({newx,newy});
                       }
                }
            }
         }
         for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='O'&&m[{i,j}]==false){
                    board[i][j]='X';
                }
            }
         }

         
    }
};