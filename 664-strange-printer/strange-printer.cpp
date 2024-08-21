class Solution {
public:
   int solve(string s,int start,int end,vector<vector<int>>&dp){
      if(start>end){
        return 0;
      }
      if(dp[start][end]!=-1){
        return dp[start][end];
      }
      int ans=1+solve(s,start+1,end,dp);
      
      for(int i=start+1;i<=end;i++){
        int a=0;
        if(s[start]==s[i]){
           a+=solve(s,start,i-1,dp)+solve(s,i+1,end,dp);
           ans=min(a,ans);
        }
      }
      return dp[start][end]=ans;
   }
    int strangePrinter(string s) {
        int start=0;
        int end=s.length()-1;
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        int ans=solve(s,start,end,dp);
        return ans;
    }
};