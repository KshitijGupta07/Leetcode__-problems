class Solution {
public:
    int solve(int m,int n,int i,int j,vector<vector<int>>&dp){
        if(i>=m||j>=n){
            return 0;
        }
        if(i==m-1&&j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left=solve(m,n,i,j+1,dp);
        int down=solve(m,n,i+1,j,dp);
        dp[i][j]=left+down;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        int i=0;
        int j=0;
       
        vector<vector<int>>dp(m,vector<int>(n,-1));
            int ans=solve(m,n,i,j,dp);

        return ans;
    }
};