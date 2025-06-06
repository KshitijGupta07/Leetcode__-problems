class Solution {
public:
    int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
         if(j==i+1){
            return 0;
         }
          if(dp[i][j]!=-1){
            return dp[i][j];
          }
        int ans=0;
        for(int k=i+1;k<j;k++){
           ans=max(ans,nums[i]*nums[k]*nums[j]+solve(nums,i,k,dp)+solve(nums,k,j,dp));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        int ans=solve(nums,0,nums.size()-1,dp);
        return ans;
    }
};