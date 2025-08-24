class Solution {
public:
   int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    for(int k=i;k<j;k++){
             ans=max(ans,solve(nums,i,k,dp)+solve(nums,k+1,j,dp)+nums[i-1]*nums[k]*nums[j]);
    }
    return dp[i][j]=ans;
     
   }
    int maxCoins(vector<int>& nums) {
        int i=0;
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int j=nums.size()-1;
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        int ans=solve(nums,1,j,dp);
        return ans;
    }
};