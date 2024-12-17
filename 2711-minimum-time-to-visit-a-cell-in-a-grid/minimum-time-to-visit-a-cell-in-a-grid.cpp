class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][1]>1&&grid[1][0]>1){
            return -1;
        }
        map<pair<int,int>,bool>visited;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>p;
        p.push({0,0,0});
        visited[{0,0}]=true;
        vector<int>r{0,1,0,-1};
        vector<int>c{1,0,-1,0};
        while(p.empty()==false){
            vector<int>top=p.top();
            p.pop();
            int t=top[0];
            int x=top[1];
            int y=top[2];
            cout<<x<<" "<<y<<endl;
            if(x==m-1&&y==n-1){
                return t;
            }
            
            for(int i=0;i<4;i++){
                if(x+r[i]>=0&&x+r[i]<m&&y+c[i]>=0&&y+c[i]<n){
                    if(visited[{x+r[i],y+c[i]}]==false){
                    int waitime=(grid[x+r[i]][y+c[i]]-t)%2;
                    waitime=waitime^1;
                    visited[{x+r[i],y+c[i]}]=true;
                    int nexttime=max(t+1,grid[x+r[i]][y+c[i]]+waitime);
                    p.push({nexttime,x+r[i],y+c[i]});
                    }
                }
            }

        }
        return -1;
    }
};