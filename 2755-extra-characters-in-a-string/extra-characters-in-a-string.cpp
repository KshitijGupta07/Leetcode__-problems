class Solution {
public:
    int solve(string s,vector<string>&dictionary,int index,map<string,bool>&m,vector<int>&dp){
          if(index>=s.length()){
            return 0;
          }
          cout<<index<<endl;
          if(dp[index]!=-1){
            return dp[index];
          }
          int ans=INT_MAX;
          for(int i=index;i<s.length();i++){
            int count=0;
            if(m[s.substr(index,i-index+1)]){
                  count+=(solve(s,dictionary,i+1,m,dp));
            }
            else{
                count+=(i-index+1+solve(s,dictionary,i+1,m,dp));
            }
            ans=min(ans,count);
          }
          return dp[index]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        map<string,bool>m;
        for(auto j:dictionary){
         m[j]=true;
        }
        vector<int>dp(s.length(),-1);
        int ans=solve(s,dictionary,0,m,dp);
        return ans;

    }
};