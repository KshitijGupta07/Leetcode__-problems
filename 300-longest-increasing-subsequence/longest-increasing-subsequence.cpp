class Solution {
public:
   int solve(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
      if(curr>=nums.size()){
        return 0;
      }
      if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
      }
      int exclude=solve(nums,curr+1,prev,dp);
      int include=0;
      if(prev==-1||nums[curr]>nums[prev]){
        include=1+solve(nums,curr+1,curr,dp);
      }
      
      dp[curr][prev+1]= max(include,exclude);
      
      return dp[curr][prev+1];

   }
   int solvetab(vector<int>&nums){
     vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,0));
      for(int i=nums.size()-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
            int include=0;
            if(j==-1||nums[i]>nums[j]){
                include=1+dp[i+1][i];
            }
            int exclude=dp[i+1][j];
            dp[i][j]=max(include,exclude);

        }
      }
      return dp[0][0];
   }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        int ans=solve(nums,0,-1,dp);

        return ans;
    }
};