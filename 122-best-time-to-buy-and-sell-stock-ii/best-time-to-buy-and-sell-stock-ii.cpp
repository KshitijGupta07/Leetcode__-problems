class Solution {
public:
   int solve(vector<int>&prices,int index,int buy,vector<vector<int>>&dp){
    if(index==prices.size()){
        return 0;
    }
    if(dp[index][buy]!=-1){
        return dp[index][buy];
    }
    int profit=0;
      if(buy==1){
        profit=max(-prices[index]+solve(prices,index+1,0,dp),solve(prices,index+1,1,dp));
      }
      else{
        profit=max(prices[index]+solve(prices,index+1,1,dp),solve(prices,index+1,0,dp));
      }
      dp[index][buy]= profit;
      return dp[index][buy];
   }
    int maxProfit(vector<int>& prices) {
       
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
         int ans=solve(prices,0,1,dp);
        return ans;
    }
};