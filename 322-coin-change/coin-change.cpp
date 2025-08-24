class Solution {
public:
   long long  solve(vector<int>&coins,int amount,int index,vector<vector<int>>&dp){
    if(index>=coins.size()||amount<0){
        return INT_MAX;
    }
    if(amount==0){
        return 0;
    }
    // if(amount==coins[index]){
    //     return 1;
    // }
    if(dp[amount][index]!=-1){
        return dp[amount][index];
    }
    
    long long  a=1+solve(coins,amount-coins[index],index,dp);
long long  b=solve(coins,amount,index+1,dp);
    return dp[amount][index]=min(a,b);

   }
    int tab(vector<int>&coins,int amount){
        vector<vector<long long >>dp(amount+1,vector<long long >(coins.size()+1,INT_MAX));
        for(int i=0;i<=coins.size();i++){
            dp[0][i]=0;
        }
        for(int j=coins.size()-1;j>=0;j--){
            for(int i=0;i<=amount;i++){
                if(i-coins[j]>=0&&dp[i-coins[j]][j]!=INT_MAX){
                    dp[i][j]=min(1+dp[i-coins[j]][j],dp[i][j+1]);
                }
                else{
                    dp[i][j]=dp[i][j+1];
                }
           
            }
        }
        // for(auto j:dp){
        //     for(auto k:j){
        //         cout<<k<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[amount][0];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size(),-1));
        // long long  ans=solve(coins,amount,0,dp);
        // if(ans==INT_MAX){
        //     return -1;
        // }
        int a=tab(coins,amount);
        if(a==INT_MAX){
            return -1;
        }
        return a;
    }
};