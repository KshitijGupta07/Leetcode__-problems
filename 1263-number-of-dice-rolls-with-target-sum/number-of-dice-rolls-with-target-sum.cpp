
class Solution {
public:
    int solve(int n,int k,int target,vector<vector<int>>&dp){
        int element=pow(10,9)+7;
        if(target<0){
            return 0;
        }
        if(n==0&&target!=0){
            return 0;
        }
        if(target==0&&n!=0){
            return 0;
        }
        if(target==0&&n==0){
            return 1;
        }
        if(dp[n][target]%element!=-1){
            return dp[n][target]%element;
        }

        int ans=0;
        for(int i=1;i<=k;i++){
        ans=(ans%element+solve(n-1,k,target-i,dp)%element)%element;
        
        }
        dp[n][target]=ans%element;
        return dp[n][target]%element;
    }
    int numRollsToTarget(int n, int k, int target) {
      int element=pow(10,9)+7;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
          int ans=solve(n,k,target,dp)%element;
        return ans;
    }
};