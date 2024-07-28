class Solution {
public:
   bool reverse(string& s,int start ,int end,vector<vector<int>>&dp){
    if(start<s.length()&&end>=0&&start>=end){
        return true;
    }
    bool ans=false;
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    if(s[start]==s[end]){
       ans= reverse(s,start+1,end-1,dp);
    }
    else{
        ans=false;
    }
     dp[start][end]=ans;
     return dp[start][end];
   }
   string solve(string &s){
    vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
    int start=0;
    int maxend=INT_MIN;
    int maxlen=INT_MIN;
    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
        
            if(reverse(s,i,j,dp)==true){
                if(maxlen<j-i+1){
                    maxlen=j-i+1;
                    start=i;
                    maxend=j;
                }
                  
            }
        }
    }
    string ans="";
     for(int i=start;i<=maxend;i++){
        ans.push_back(s[i]);
     }
    return ans;
      
   }
    string longestPalindrome(string s) {
        int start=0;
        int end=s.length()-1;
        string ans=solve(s);
        return ans;
    }
};