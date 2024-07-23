class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        if(nums.size()==2){
            return 2;
        }
        unordered_map<int,int>dp[nums.size()+1];
        int ans=2;
        for(int i=0;i<nums.size()-1;i++){
            
            for(int j=i+1;j<nums.size();j++){
               int diff=nums[j]-nums[i];
               
               if(dp[i].count(diff)){
                    dp[j][diff]=dp[i][diff]+1;
               }
               else{
                dp[j][diff]=2;
               }
            
            
               ans=max(ans,dp[j][diff]);
            }
        }
        return ans;
    }
};