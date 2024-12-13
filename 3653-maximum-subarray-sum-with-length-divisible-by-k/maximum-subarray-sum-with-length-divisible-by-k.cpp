class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long>dp(k+1,INT_MAX);
        dp[0]=0;
        long long ans=pow(-2,63);
        long long sum=0;
        for(int i=0;i<nums.size();i++){
               sum+=nums[i];
            if(dp[(i+1)%k]!=INT_MAX){
                ans=max(ans,sum-dp[(i+1)%k]);
                 
            }
             long long element=dp[(i+1)%k];
                dp[(i+1)%k]=min(element,sum);
        }
        return ans;

    }
};