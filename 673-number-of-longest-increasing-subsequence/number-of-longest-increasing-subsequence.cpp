class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        vector<int>count(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                  if(nums[j]>nums[i]){
                    if(dp[j]<dp[i]+1){
                        dp[j]=dp[i]+1;
                        count[j]=count[i];
                    }
                    else if(dp[j]==dp[i]+1){
                        count[j]+=count[i];
                    }
                  }
            }
        }
        int ans=0;
        for(auto j:dp){
            ans=max(ans,j);
        }
        int counter=0;
        for(int i=0;i<dp.size();i++){
            if(dp[i]==ans){
                counter=counter +count[i];
            }
        }
        return counter;
    }
};