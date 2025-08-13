class Solution {
public:
   int solve(vector<int>&prices,int index,bool signal,vector<vector<int>>&dp){
    if(index>=prices.size()){
        return 0;
    }
    if(dp[index][signal]!=-1){
        return dp[index][signal];
    }
    if(signal==false){
        return dp[index][signal]=max( -prices[index]+solve(prices,index+1,1-signal,dp),solve(prices,index+1,signal,dp));
    }
    return dp[index][signal]=max(prices[index]+solve(prices,index+2,1-signal,dp),solve(prices,index+1,signal,dp));
   }
    int maxProfit(vector<int>& prices) {
        int index=0;
        bool signal=false;
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        int ans=solve(prices,index,signal,dp);
        return ans;
    }
};