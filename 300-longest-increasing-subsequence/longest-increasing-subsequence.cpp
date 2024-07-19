class Solution {
public:
    int solve(vector<int>&nums,int prev,int curr,vector<vector<int>>&dp){
        
         if(curr>=nums.size()){
            return 0;
         }
          if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
          }
         int include=0;
         if(prev==-1||nums[curr]>nums[prev])
          include=1+solve(nums,curr,curr+1,dp);
           int exclude=solve(nums,prev,curr+1,dp);
         dp[curr][prev+1]= max(include,exclude);
         return dp[curr][prev+1];
         
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        
       return  solve(nums,-1,0,dp);
    }
};