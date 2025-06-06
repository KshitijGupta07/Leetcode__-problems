class Solution {
public:
   bool solve(vector<int>&nums,int sum,int i,vector<vector<int>>&dp){
    if(sum<0){
        return false;
    }
    if(i>=nums.size()){
        return sum==0;
    }
    if(dp[sum][i]!=-1){
        return dp[sum][i];
    }
    
      bool inc=solve(nums,sum-nums[i],i+1,dp);
      bool exc=solve(nums,sum,i+1,dp);
      return dp[sum][i]=inc||exc;
   }
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(auto j:nums){
            sum+=j;
        }
        if(sum%2==1){
            return false;
        }
        int a=sum/2 ;
        vector<vector<int>>dp(20001,vector<int>(201,-1));
        bool ans=solve(nums,a,0,dp);
        return ans;
    }
};