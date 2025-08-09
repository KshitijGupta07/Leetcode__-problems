class Solution {
public:
    int solve(vector<int>&nums,int i,int end,vector<int>&dp){
        cout<<i<<endl;
        if(i>end){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int x=nums[i]+solve(nums,i+2,end,dp);
        int y=solve(nums,i+1,end,dp);
        return dp[i]=max(x,y);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>dp(nums.size(),-1);
        int ans=solve(nums,0,nums.size()-2,dp);
        dp.clear();
        dp.resize(nums.size(),-1);
        int ans2=solve(nums,1,nums.size()-1,dp);
        return max(ans,ans2);
    }
};