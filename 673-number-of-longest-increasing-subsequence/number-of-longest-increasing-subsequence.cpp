class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        vector<int>count(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(nums[j]>nums[i]){
                    if(dp[j]<dp[i]+1){
                        count[j]=count[i];
                        dp[j]=dp[i]+1;
                    }
                    else if(dp[j]==dp[i]+1){
                        count[j]+=count[i];
                    }
                }
                
            }
        }
        int maxi=0;
        for(auto j:dp){
            maxi=max(maxi,j);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==maxi){
                ans+=count[i];
            }
        }
        return ans;
    }
};