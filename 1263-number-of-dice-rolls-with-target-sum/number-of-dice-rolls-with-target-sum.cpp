
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
    int bottomup(int n,int k, int target){
        int element=pow(10,9)+7;
        // vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        vector<int>curr(target+1,0);
        vector<int>prev(target+1,0);
        prev[0]=1;
        
        
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=target;j++){
                int ans=0;
                for(int x=1;x<=k;x++){
                    if(j>=x){
            ans=(ans%element+prev[j-x]%element)%element;
                    }
                }
                curr[j]=ans%element;
            
            }
          prev=curr;
           
        }
        return prev[target];
    }
    int numRollsToTarget(int n, int k, int target) {
      int element=pow(10,9)+7;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
          int ans=bottomup(n,k,target)%element;

        return ans;
    }
};