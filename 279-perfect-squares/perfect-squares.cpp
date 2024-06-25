class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n<=0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solve(n-i*i,dp)); 

        }
        dp[n]=ans;
        return dp[n];
    }
    int tab(int& n){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(i-j*j>=0){
                dp[i]=min(dp[i],1+dp[i-j*j]);
                }
            }
        }
        return dp[n];
    }
    int numSquares(int n) {
        // vector<int>dp(n+1,-1);
        // int ans=solve(n,dp);
        int a=tab(n);
        return a;
    }
};