class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>p;
       int ans=0;
       int m=heightMap.size()-1;
       int n=heightMap[0].size()-1;
        vector<vector<bool>>visited(heightMap.size(),vector<bool>(heightMap[0].size(),false));
     for(int i=0;i<heightMap.size();i++){
            p.push({heightMap[i][0],i,0});
            p.push({heightMap[i][visited[0].size()-1],i,n});
            visited[i][0]=true;
            visited[i][visited[0].size()-1]=true;
        }
        for(int j=0;j<heightMap[0].size();j++){
            p.push({heightMap[0][j],0,j});
            p.push({heightMap[visited.size()-1][j],m,j});
            visited[0][j]=true;
            visited[visited.size()-1][j]=true;
        }
        vector<int>a{1,-1,0,0};
        vector<int>b{0,0,-1,1};
        while(p.empty()==false){
            vector<int>top=p.top();
            p.pop();
            int h=top[0];
            int r=top[1];
            int c=top[2];
            for(int i=0;i<4;i++){
                int newr=r+a[i];
                int newc=c+b[i];
                if(newr>=0&&newr<visited.size()&&newc>=0&&newc<visited[0].size()&&visited[newr][newc]==false){
                    ans+=max(0,h-heightMap[newr][newc]);
                    p.push({max(h,heightMap[newr][newc]),newr,newc});
                    visited[newr][newc]=true;
                }
            }


        }
        return ans;
    }
};