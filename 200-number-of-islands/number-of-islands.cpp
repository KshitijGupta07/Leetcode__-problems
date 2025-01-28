class Solution {
public:

   void solve(vector<vector<char>>&grid,int i,int j,vector<vector<bool>>&visited){
       if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||visited[i][j]==true||grid[i][j]=='0'){
        return;
       }
       visited[i][j]=true;
       solve(grid,i+1,j,visited);
       solve(grid,i-1,j,visited);
       solve(grid,i,j-1,visited);
       solve(grid,i,j+1,visited);
   }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(visited[i][j]==false&&grid[i][j]=='1'){
                       solve(grid,i,j,visited);
                       count++;
                }
            }
         }
         return count;
    }
};