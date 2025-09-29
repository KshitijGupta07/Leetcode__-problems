class Solution {
public:
   int solve(vector<int>&nums, int target,int i){
    if(i>=nums.size()){
        return target==0;
    }
     int ans1=solve(nums,target-nums[i],i+1);
     int ans2=solve(nums,target+nums[i],i+1);
     return ans1+ans2;
        }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=solve(nums,target,0);
        return ans;
    }
};