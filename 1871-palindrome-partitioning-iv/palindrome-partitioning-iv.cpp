class Solution {
public:
  bool check(string& s, int start ,int end){
      while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
      }
      return true;
  }
    bool solve(string& s,int i,int count,vector<vector<int>>&dp,vector<vector<bool>>&dp2){
        if(i>=s.length()){
           return false;
        }
         if(count==2){
           if(dp2[i][s.length()-1]==true){
            return true;
           }
           else{
            return false;
           }
        }
        if(dp[i][count]!=-1){
            return dp[i][count];
        }
       
        bool ans=false;
        
        for(int index=i;index<s.length();index++){
            if(check(s,i,index)){
                ans=ans||solve(s,index+1,count+1,dp,dp2);
            }
        }
        return dp[i][count]=ans;
    }
    bool checkPartitioning(string s) {
        int i=0;
        vector<vector<int>>dp(s.length(),vector<int>(3,-1));
        vector<vector<bool>>dp2(s.length(),vector<bool>(s.length(),false));
        for(int i=s.length()-1;i>=0;i--){
            for(int j=s.length()-1;j>=i;j--){
                if(s[i]==s[j]&&(j-i<=2||dp2[i+1][j-1])){
                     dp2[i][j]=true;
                }
            }
        }
        bool ans=solve(s,i,0,dp,dp2);
        return ans;
    }
};