class Solution {
public:
//    long long  solve(vector<int>&coins,int amount,vector<int>&dp){
//       if(amount==0){
//         return 0;
//       }
//       if(amount<0){
//         return INT_MAX;
//       }
//       if(dp[amount]!=INT_MAX){
//         return dp[amount];
//       }
//       long long ans=INT_MAX;
//       for(int i=0;i<coins.size();i++){
//              ans=min(ans,1+solve(coins,amount-coins[i],dp));
//       }
//       return dp[amount]=ans;

//    }
   int tab(vector<int>&coins,int amount){
    vector<long long >dp(amount+1,INT_MAX);
    dp[0]=0;
    for(int i=0;i<coins.size();i++){
        for(int j=1;j<=amount;j++){
            if(j-coins[i]>=0){
                if(dp[j-coins[i]]!=INT_MAX){
                dp[j]=min(dp[j],1+dp[j-coins[i]]);
                }
            }
            
        }
        
    }
    return dp[amount];
   }
    int coinChange(vector<int>& coins, int amount) {
        int index=0;
    
        int ans=tab(coins,amount);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};