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
   int solvetab(vector<int>&prices){
    vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
    int j=0;
      for(int i=prices.size()-1;i>=0;i--){
        int profit=0;
        for( j=0;j<=1;j++){
            if(j==1){
                profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            }
            else{
                profit=max(prices[i]+dp[i+1][1],dp[i+1][0]);
            }
            dp[i][j]=profit;
        }
        
      }
      return dp[0][1];
   }
    int maxProfit(vector<int>& prices) {
       
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
         int ans=solvetab(prices);
        return ans;
    }
};