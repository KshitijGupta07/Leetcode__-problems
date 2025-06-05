class Solution {
public:
   bool check(string &s,int i,int j,vector<vector<int>>&dp){
       if(i<s.length()&&j>=0&&i>=j){
        return dp[i][j]=true;
       }
       if(s[i]!=s[j]){
        return dp[i][j]=false;
       }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }
       
       return dp[i][j]=check(s,i+1,j-1,dp);
   }
    string longestPalindrome(string s) {
        int ans=0;
        int start=0;
        int end=0;
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length();j++){
                  if(check(s,i,j,dp)){
                     if(ans<j-i+1){
                        start=i;
                        end=j;
                        ans=j-i+1;
                     }
                  }
            }
        }
        string pali="";
        for(int x=start;x<=end;x++){
             pali.push_back(s[x]);
        }
        return pali;
    }
};