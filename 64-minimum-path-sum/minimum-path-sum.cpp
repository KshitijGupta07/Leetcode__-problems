class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        if(i>=grid.size()||j>=grid[0].size()){
            return 0;
        }
        if(i==grid.size()-1&&j==grid[0].size()-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=INT_MAX;
        int b=INT_MAX;
        if(i+1<grid.size())
        a=min(a,grid[i][j]+solve(grid,i+1,j,dp));
        if(j+1<grid[0].size())
        b=min(b,grid[i][j]+solve(grid,i,j+1,dp));
        return dp[i][j]=min(a,b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
       int ans=solve(grid,0,0,dp);
       return ans; 
    }
};