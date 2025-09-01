class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>prev(nums.size(),-1);
        vector<int>dp(nums.size(),1);
        int maxlen=1;
        int maxindex=0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                }
            }
            if(dp[i]>maxlen){
                maxlen=dp[i];
                maxindex=i;
            }
        }
        vector<int>ans;
        for(int j=maxindex;j!=-1;j=prev[j]){
               ans.push_back(nums[j]);

        }
        return ans;
        
    }
};