class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));

        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=true;
                }
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        if(count==0){
            return 0;
        }
        if(q.size()==0){
            return -1;
        }
        vector<int>a{1,-1,0,0};
        vector<int>b{0,0,1,-1};
         int timer=0;

        while(q.empty()==false){
               int size=q.size();
               bool signal=false;
               for(int i=0;i<size;i++){
                
                  int x=q.front().first;
                  int y=q.front().second;
                  q.pop();
                  for(int i=0;i<4;i++){
                     if(x+a[i]>=0&&x+a[i]<m&&y+b[i]>=0&&y+b[i]<n&&visited[x+a[i]][y+b[i]]==false){
                        if(grid[x+a[i]][y+b[i]]==1){
                            signal=true;
                            count-=1;
                            grid[x+a[i]][y+b[i]]=2;
                            q.push({x+a[i],y+b[i]});
                            visited[x+a[i]][y+b[i]]=true;
                        }
                     }
                  }

               }
               if(signal){
                timer++;
               }
               
        }
        if(count>0){
            return -1;
        }
        return timer;
    }
};