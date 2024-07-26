class Solution {
public:
    int solve(string &s,int start ,int end,vector<vector<int>>&dp){
        if(start>end){
            return 0;
        }
        if(dp[start][end]!=-1){
              return dp[start][end];
        }

    int ans=INT_MIN;
        if(s[start]==s[end]){
            if(start==end){
                ans=max(ans,1+solve(s,start+1,end-1,dp));
            }
            else{
            ans=max(ans,2+solve(s,start+1,end-1,dp));
        
            
            }
        }
        else{
            ans=max(ans,solve(s,start+1,end-1,dp));
            
            ans=max(ans,solve(s,start+1,end,dp));
            
            ans=max(ans,solve(s,start,end-1,dp));
        }
        dp[start][end]=ans;
        return dp[start][end];
    }
    int longestPalindromeSubseq(string s) {
        if(s.length()==1){
            return 1;
        }
        int start=0;
        int end=s.length()-1;
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        int ans=solve(s,start,end,dp);
        return ans;
    }
};