class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
         if(arr.size()==1){
            return 1;
         }
         unordered_map<int,int>dp;
         int ans=0;
         for(int i=0;i<arr.size();i++){
             int temp=arr[i]-difference;
             if(dp.count(temp)){
                dp[arr[i]]=1+dp[temp];
             }
             else{
                dp[arr[i]]=1;
             }
             ans=max(ans,dp[arr[i]]);
         }
         return ans;
    }
};