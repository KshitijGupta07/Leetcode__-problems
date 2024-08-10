class Solution {
public:
   int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i==0&&j==0){
        return grid[i][j];
    }
     
    if(i<0||j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int a=INT_MAX;
    int b=INT_MAX;
    if(i>0){
     a=grid[i][j]+solve(i-1,j,grid,dp);
    }
    if(j>0){
     b=grid[i][j]+solve(i,j-1,grid,dp);
    }
      dp[i][j]=min(a,b);
      return dp[i][j];
   }
    int minPathSum(vector<vector<int>>& grid) {
        int i=grid.size()-1;
        int j=grid[0].size()-1;
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        int ans=solve(i,j,grid,dp);
        return ans;
    }
};