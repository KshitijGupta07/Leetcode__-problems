class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({health-grid[0][0],{0,0}});
        vector<pair<int,int>>v;
        v.push_back({0,1});
        v.push_back({0,-1});
        v.push_back({1,0});
        v.push_back({-1,0});
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        visited[0][0]=true;
        while(pq.empty()==false){
            pair<int,pair<int,int>>top=pq.top();
            pq.pop();

             int x=top.second.first;
                int y=top.second.second;
                int he=top.first;

                if(x==n-1&&y==m-1){
                    if(he>=1){
                        return true;
                    }
                }

            for(int i=0;i<4;i++){
                cout<<x<<" "<<y<<endl;
                 int nx=x+v[i].first;
                 int ny=y+v[i].second;
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==0){
                    if(visited[nx][ny]==false){
                    visited[nx][ny]=true;
                      pq.push({he,{nx,ny}});
                    }
                 
                }
               else if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==1){
                     if(visited[nx][ny]==false){
                    visited[nx][ny]=true;
                      pq.push({he-1,{nx,ny}});
                    }
                }
            }
        }
        return false;
    }
};