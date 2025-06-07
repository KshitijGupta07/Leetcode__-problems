class Solution {
public:
   bool solve(string s,map<string,bool>&m,int i,int j,vector<vector<int>>&dp){
       if(j==s.length()-1){
          return m[s.substr(i,j-i+1)];
       }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }
    
       
       if(m[s.substr(i,j-i+1)]){
           bool ans1=solve(s,m,j+1,j+1,dp);
           bool ans2=solve(s,m,i,j+1,dp);
           return dp[i][j]=ans1||ans2;

       }
       
        return dp[i][j]=solve(s,m,i,j+1,dp);
       
       
       
   }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,bool>m;
        for(auto j:wordDict){
            m[j]=true;
        }
        int i=0;
        string temp="";
        m[""]=true;
         vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        bool ans=solve(s,m,i,0,dp);
        return ans;
    }
};