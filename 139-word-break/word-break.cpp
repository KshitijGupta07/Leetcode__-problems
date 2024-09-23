class Solution {
public:
   bool solve(string s,vector<string>&wordDict,int i,int j,map<string,bool>&m,vector<vector<int>>&dp){
    
      if(j==s.length()-1){
        cout<<i<<" "<<j<<endl;
         if(m[s.substr(i,j-i+1)]){
            return true;
         }
         else{
            return false;
         }
      }
      if(dp[i][j]!=-1){
        return dp[i][j];
      }
      bool ans=0;
      bool ans2=0;
      if(m[s.substr(i,j-i+1)]){
        cout<<i<<" "<<j<<endl;
        ans=solve(s,wordDict,j+1,j+1,m,dp);
        ans2=solve(s,wordDict,i,j+1,m,dp);
      }
      else{
        cout<<i<<" "<<j<<endl;
        ans=solve(s,wordDict,i,j+1,m,dp);
      }
      
      return dp[i][j]= ans||ans2;

   }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        map<string,bool>m;
        for(auto j:wordDict){
            m[j]=true;
        }
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        bool ans=solve(s,wordDict,0,0,m,dp);
        return ans;
    }
};