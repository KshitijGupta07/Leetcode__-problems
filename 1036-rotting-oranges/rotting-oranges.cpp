class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        map<pair<int,int>,bool>m;
        for(int i=0;i<grid.size();i++){
              for(int j=0;j<grid[0].size();j++){
                  if(grid[i][j]==2){
                     q.push({i,j});
                     m[{i,j}]=true;
                  }
              }
        }
        int timer=0;
        vector<int>dx{1,-1,0,0};
        vector<int>dy{0,0,-1,1};

        while(q.empty()==false){
            int a=q.size();
            bool check=false;
            for(int i=0;i<a;i++){
                   pair<int,int>front=q.front();
                   q.pop();
                   for(int j=0;j<4;j++){
                      int x=front.first+dx[j];
                      int y=front.second+dy[j];
                       if(x>=0&&y>=0&&x<grid.size()&&y<grid[0].size()&&m[{x,y}]==false&&grid[x][y]==1){
                        check=true;
                        grid[x][y]=2;
                         q.push({x,y});
                         m[{x,y}]=true;
                       }
                   }
            }
            if(check==true){
                timer++;
            }
            
        }
        for(auto j:grid){
            for(auto k:j){
                if(k==1){
                    return -1;
                }
            }
        }
        return timer;
    }
};