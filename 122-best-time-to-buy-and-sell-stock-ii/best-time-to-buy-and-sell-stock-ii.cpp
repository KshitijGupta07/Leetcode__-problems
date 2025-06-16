class Solution {
public:
   int solve(vector<int>&prices,int i,int buy,vector<vector<int>>&dp){
    if(i==prices.size())return 0;
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
      int ans=INT_MIN;
      if(buy==1){
        ans=max(-prices[i]+solve(prices,i+1,0,dp),solve(prices,i+1,1,dp));
      }
      else{
        ans=max(prices[i]+solve(prices,i+1,1,dp),solve(prices,i+1,0,dp));
      }
      return dp[i][buy]=ans;
   }
   int tab(vector<int>&prices){
     vector<int>prev(2,0);
     vector<int>curr(2,0);
      for(int i=prices.size()-1;i>=0;i--){
        for(int j=0;j<2;j++){
            int ans=0;
            if(j==0){
                ans=max(-prices[i]+curr[1],curr[0]);
            }
            else{
                ans=max(prices[i]+curr[0],curr[1]);
            }
            curr[j]=ans;
        }
        prev=curr;
      }
      return prev[0];
   }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        int ans=tab(prices);
        return ans;
    }
};