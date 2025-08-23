class Solution {
public:
   bool solve(vector<int>&nums,int sum,int i,vector<vector<int>>&dp){
    if(i>=nums.size()||sum<0){
        return false;
    }
    if(sum==nums[i]){
        return true;
    }
    if(dp[sum][i]!=-1){
        return dp[sum][i];
    }
    bool ans1=solve(nums,sum-nums[i],i+1,dp);
    bool ans2=solve(nums,sum,i+1,dp);
    return dp[sum][i]=ans1||ans2;
   }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto j:nums){
            sum+=j;
        }
        if(sum%2==1){
            return false;
        }
        vector<vector<int>>dp(sum/2 +1,vector<int>(nums.size(),-1));
        bool ans=solve(nums,sum/2 ,0,dp);
        return ans;
    }
};