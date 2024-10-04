class Solution {
public:
   bool solve(string s,string p,int i,int j,vector<vector<int>>&dp){
    cout<<i<<" "<<j<<endl;
    if(j==p.length()){
        if(i==s.length()){
            return true;
            
        }
        else{
            return false;
        }
    }
   
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
     bool charfirst=false;
     if(i<s.length()&&(p[j]==s[i]||p[j]=='.')){
        charfirst=true;
     }
     if(p[j+1]=='*'){
        bool take=charfirst&&solve(s,p,i+1,j,dp);
        bool not_take=solve(s,p,i,j+2,dp);
       return dp[i][j]=take||not_take;
     }
     return dp[i][j]=charfirst&&solve(s,p,i+1,j+1,dp);

   }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(21,vector<int>(21,-1));
        bool ans=solve(s,p,0,0,dp);
        return ans;
    }
};