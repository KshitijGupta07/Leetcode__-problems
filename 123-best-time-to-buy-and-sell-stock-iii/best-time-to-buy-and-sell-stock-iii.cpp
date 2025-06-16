class Solution {
public:
    int solve(vector<int>&prices,int index,int buy,int count,vector<vector<vector<int>>>&dp){
        if(count==0||index==prices.size()){
            return 0;
        }
        if(dp[index][buy][count]!=-1){
            return dp[index][buy][count];
        }
        if(buy==0){
            return dp[index][buy][count]=max(-prices[index]+solve(prices,index+1,1,count,dp),solve(prices,index+1,0,count,dp));
        }
        return dp[index][buy][count]=max(prices[index]+solve(prices,index+1,0,count-1,dp),solve(prices,index+1,1,count,dp));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        int ans=solve(prices,0,0,2,dp);
        return ans;
    }
};