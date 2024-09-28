class Solution {
public:
   int solve(vector<vector<bool>>&visited,int i,int j,int m,int n,vector<vector<int>>&grid){
     if(i<0||i>=m||j<0||j>=n||grid[i][j]==0||visited[i][j]==true){
        return 0;
     }
     visited[i][j]=true;
     
   
     
     int ans=1+solve(visited,i+1,j,m,n,grid)+solve(visited,i-1,j,m,n,grid)+solve(visited,i,j+1,m,n,grid)+solve(visited,i,j-1,m,n,grid);
     
     return ans;

   }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size()));
        int ans=INT_MIN;
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(grid[x][y]==1&&visited[x][y]==false){
                    
                    ans=max(ans,solve(visited,x,y,m,n,grid));
                }

            }
        }
        if(ans==INT_MIN){
            return 0;
        }
        return ans;
    }
};