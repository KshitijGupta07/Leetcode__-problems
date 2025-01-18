class Solution {
public:
   int bfs(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>distance(grid.size(),vector<int>(grid[0].size(),111111));
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
       q.push({0,0,0});
       distance[0][0]=0;
       vector<int>a{0,0,1,-1};
       vector<int>b{1,-1,0,0};
        while(q.empty()==false){
            vector<int>top=q.top();
            q.pop();
            int dis=top[0];
         
            int x=top[1];
            int y=top[2];
           
            if(distance[x][y]!=dis){
                continue;
            }
            for(int i=0;i<4;i++){
                int r=x+a[i];
                int c=y+b[i];
               
            if(r>=0&&r<m&&c>=0&&c<n){
                int newc=dis;
                if(i+1!=grid[x][y]){
                    newc+=1;
                }
                
                if(distance[r][c]>newc){
                    distance[r][c]=newc;
                    q.push({newc,r,c});
                }
            }
            }
            
        }
        return distance[m-1][n-1];
   }
    int minCost(vector<vector<int>>& grid) {
       return bfs(grid);
        
    }
};