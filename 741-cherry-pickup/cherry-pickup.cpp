class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,int k,vector<vector<vector<int>>>&dp){
        int l=i+j-k;
        
    
        if(i>=grid.size()||j>=grid[0].size()||k>=grid.size()||l>=grid.size()||grid[i][j]==-1||grid[k][l]==-1){
            return INT_MIN;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
         if(i==grid.size()-1&&j==grid.size()-1){
            return grid[i][j];
         }
          int ans=grid[i][j];
          if(i!=k){
            cout<<l<<endl;
            ans+=grid[k][l];
          }
          int temp=max(solve(grid,i+1,j,k+1,dp),solve(grid ,i,j+1,k,dp));
          temp=max(temp,solve(grid,i+1,j,k,dp));
          temp=max(temp,solve(grid,i,j+1,k+1,dp));
     
        
        return dp[i][j][k]=ans+temp;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid.size(),vector<int>(grid.size(),-1)));
        int a=solve(grid,0,0,0,dp);
        return max(a,0);
    }
};