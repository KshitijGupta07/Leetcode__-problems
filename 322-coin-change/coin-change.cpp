class Solution {
public:
   int solve(vector<int>&coins,int amount){
    vector<int>dp(amount+1,INT_MAX);
    dp[0]=0;
    
    for(int i=1;i<=amount;i++){
        int mini=INT_MAX;
        for(int j=0;j<coins.size();j++){
            if(i-coins[j]>-1){
            int ans=dp[i-coins[j]];
            if(ans!=INT_MAX)
            dp[i]=min(dp[i],ans+1);
            }
        }
        
    
    }
    return dp[amount];
   }
   
   
    int coinChange(vector<int>& coins, int amount) {
        
        
        
        int ans=solve(coins,amount);
        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
        
        
        return -2;
    }
};