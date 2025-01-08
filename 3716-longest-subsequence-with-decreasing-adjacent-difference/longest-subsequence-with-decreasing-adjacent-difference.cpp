class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<vector<int>>dp(301,vector<int>(301,0));
        int maxi=0;
        for(int i=0;i<=300;i++){
            dp[nums[0]][i]=1;
        }
        for(int i=1;i<nums.size();i++){
            int curr=nums[i];
        
            for(int j=0;j<=300;j++){
                int c=0;
                 int val=curr-j;
                 if(val>0){
                    c=max(c,dp[val][j]+1);
                 }
                 if(curr+j<=300){
                    c=max(c,dp[curr+j][j]+1);
                 }
                 dp[curr][j]=max(c,dp[curr][j]);
            }
            for(int j=299;j>=0;j--){
                dp[curr][j]=max(dp[curr][j],dp[curr][j+1]);
                maxi=max(maxi,dp[curr][j]);
            }
            
        }
        return maxi;
    }
};