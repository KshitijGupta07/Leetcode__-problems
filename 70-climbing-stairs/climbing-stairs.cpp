class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(dp[n]!=-1){
            return dp[n];
        }
        if(n==0||n==1){
            return 1;
        }
       return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
       int ans=solve(n,dp);
       return ans;
    }
};