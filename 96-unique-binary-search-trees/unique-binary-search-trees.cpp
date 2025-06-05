class Solution {
public:
    int solve(int n,vector<int>&dp){
    
        if(n==1||n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
       
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=solve(i,dp)*solve(n-1-i,dp);
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        
        int ans=solve(n,dp);
        return ans;
    }
};