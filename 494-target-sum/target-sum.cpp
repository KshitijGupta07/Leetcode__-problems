class Solution {
public: 
   int solve(vector<int>&nums,int target,int index){
       if(index>=nums.size()){
           if(target==0){
            return 1;
           }
           else{
            return INT_MAX;
           }
       }
       int a=solve(nums,target+nums[index],index+1);
       int b=solve(nums,target-nums[index],index+1);
       if(a==INT_MAX){
        return b;
       }
       if(b==INT_MAX){
        return a;
       }
       return a+b;
   }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=solve(nums,target,0);
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};