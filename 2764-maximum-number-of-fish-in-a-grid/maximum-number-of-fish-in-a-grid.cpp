class Solution {
public:
   int bfs(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&visited){
          if(i<0||i>=grid.size()||j>=grid[0].size()||j<0||visited[i][j]==true||grid[i][j]==0){
            return 0;
          }
          visited[i][j]=true;
          int a=bfs(grid,i+1,j,visited);
          int b=bfs(grid,i-1,j,visited);
          int c=bfs(grid,i,j-1,visited);
          int d=bfs(grid,i,j+1,visited);
          return grid[i][j]+a+b+c+d;
   }
    int findMaxFish(vector<vector<int>>& grid) {
       
        int ans=INT_MIN;
         vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
             
              if(grid[i][j]>0&&visited[i][j]==false)
              ans=max(ans,bfs(grid,i,j,visited));
              
               
                
            }
        }
 
        return max(ans,0);
    }
};