class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int counter=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    counter++;
                }
            }
        }
        if(counter==0){
            return 0;
        }
        vector<int>xi{1,-1,0,0};
        vector<int>yi{0,0,-1,1};
        int minute=0;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        while(q.empty()==false){
                 int size=q.size();
                 bool check=false;
                 for(int j=0;j<size;j++){
                    pair<int,int>front=q.front();
                    int x=front.first;
                    int y=front.second;
                    q.pop();
                    visited[x][y]=true;
                    
                     for(int i=0;i<4;i++){
                        if(x+xi[i]<grid.size()&&y+yi[i]<grid[0].size()&&visited[x+xi[i]][y+yi[i]]==false){
                            if(grid[x+xi[i]][y+yi[i]]==1){
                                check=true;
                                grid[x+xi[i]][y+yi[i]]=2;
                                 q.push({x+xi[i],y+yi[i]});
                            }
                            if(grid[x+xi[i]][y+yi[i]]==2){
                                q.push({x+xi[i],y+yi[i]});
                            }
                           
                        }
                     }
                     

                 }
                 if(check==true){
                 minute++;
                 }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
            cout<<endl;
        }
        return minute ;
    }
};