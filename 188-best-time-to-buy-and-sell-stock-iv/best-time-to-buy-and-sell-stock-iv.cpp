class Solution {
public:
 int solve(vector<int>&prices,int index,bool signal,int count,vector<vector<vector<int>>>&dp,int k){
    if(index>=prices.size()||count>=k){
        return 0;
    }
    if(dp[index][signal][count]!=-1){
        return dp[index][signal][count];
    }
     if(signal==false){
        return dp[index][signal][count]=max(-prices[index]+solve(prices,index+1,1-signal,count,dp,k),solve(prices,index+1,signal,count,dp,k));
     }
     return dp[index][signal][count]=max(prices[index]+solve(prices,index+1,1-signal,count+1,dp,k),solve(prices,index+1,signal,count,dp,k));
   }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k,-1)));
       int ans=solve(prices,0,false,0,dp,k);
       return ans; 
    }
};