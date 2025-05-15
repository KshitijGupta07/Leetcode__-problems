class Solution {
public:
   bool check(string& s,int i,int j,vector<vector<int>>&dp){
       if(i<s.length()&&j>=0&&i>=j){
        return dp[i][j]=true;
       }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }
       if(s[i]!=s[j]){
        return dp[i][j]=false;
       }
       
       return dp[i][j]=check(s,i+1,j-1,dp);
   }
    string longestPalindrome(string s) {
        int start=-1;
        int end=-1;
        int maxlen=INT_MIN;
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(check(s,i,j,dp)){
                   
                     if(maxlen<j-i+1){
                         start=i;
                         end=j;
                        maxlen=j-i+1;
                     }
                }
            }
        }
        string ans="";
        for(int i=start;i<=end;i++){
            ans.push_back(s[i]);
        }
        cout<<start<<" "<<end<<endl;
        return ans;
    }
};