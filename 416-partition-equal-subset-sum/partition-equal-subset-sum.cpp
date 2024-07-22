class Solution {
public:
    bool solve(vector<int>&nums,int target,int index,vector<vector<int>>&dp){
        if(index>=nums.size()){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[target][index]!=-1){
             return dp[target][index];
        }
        bool include=solve(nums,target-nums[index],index+1,dp);
        bool exclude=solve(nums,target,index+1,dp);
         dp[target][index]= include|exclude;
         return dp[target][index];
    }
    bool solvetab(vector<int>&nums,int target){
        vector<vector<int>>dp(target+1,vector<int>(nums.size()+1,0));
           for(int i=0;i<nums.size()+1;i++){
            dp[0][i]=1;
           }
           for(int i=target;i>=0;i--){
            for(int j=nums.size()-1;j>=0;j--){
                bool include=false;
                if(i>=nums[j]){
                 include=dp[i-nums[j]][j+1];
                }
                bool exclude=dp[i][j+1];
                dp[i][j]=include|exclude;
            }
           }
           return dp[target][0];
    }
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }
        if(totalsum%2==1){
            return false;
        }
        
        int target=totalsum/2;
        vector<vector<int>>dp(target+1,vector<int>(nums.size(),-1));
        return solve(nums,target,0,dp);
    }
};