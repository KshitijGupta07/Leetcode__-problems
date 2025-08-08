class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<vector<int>,vector<vector<int>>,greater<>>q;
        q.push({1,0,0});
        vector<vector<int>>dis(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        if(grid[0][0]==1||grid[grid.size()-1][grid[0].size()-1]==1){
            return -1;
        }
        dis[0][0]=1;
        vector<int>dx{1,-1,0,0,1,-1,1,-1};
        vector<int>dy{0,0,-1,1,1,-1,-1,1};
        
        while(q.empty()==false){
    
            int x=q.top()[1];
            int y=q.top()[2];
            int w=q.top()[0];
            q.pop();
            cout<<x<<" "<<y<<endl;
            
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&&dis[nx][ny]>1+w&&grid[nx][ny]==0){
                    dis[nx][ny]=1+w;
                    q.push({1+w,nx,ny});
                
                }
            }
        }
        if(dis[grid.size()-1][grid[0].size()-1]==INT_MAX){
            return -1;
        }
        return dis[grid.size()-1][grid[0].size()-1];
    }
};