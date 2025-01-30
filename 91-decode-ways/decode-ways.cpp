class Solution {
public:
   int solve(string s,int index,vector<int>&dp){
    if(index>=s.length()){
        return 1;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    string x="";
    int ans=0;
    int ans2=0;
    x.push_back(s[index]);
    if(x[0]!='0'){

      ans=solve(s,index+1,dp);
    }
    if(index+1<s.length()){
        x.push_back(s[index+1]);
        if(x[0]!='0'&&stoi(x)<27){
      ans2=solve(s,index+2,dp);
    }
    }
    return dp[index]=ans+ans2;

   }
    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
        int ans=solve(s,0,dp);
        return ans;
        
    }
};