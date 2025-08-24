class Solution {
public:
  int solve(vector<int>&arr,int k,int index,vector<int>&dp){
    if(index>=arr.size()){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int maxi=0;
    int n=arr.size();
    int ans=0;
     for(int i=index;i<min(n,index+k);i++){
        maxi=max(maxi,arr[i]);
        ans=max(ans,maxi*(i-index+1)+solve(arr,k,i+1,dp));

     }
     return dp[index]=ans;
  }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        int ans=solve(arr,k,0,dp);
        return ans;
    }
};