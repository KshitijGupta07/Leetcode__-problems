class Solution {
public:
    int solvetab(string text1,string text2){
        vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));
    
        for(int i=text1.length()-1;i>=0;i--){
            int ans=0;
            for(int j=text2.length()-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    ans=1+dp[i+1][j+1];
                }
                else{
                    ans=max(dp[i+1][j],dp[i][j+1]);
                }
                  dp[i][j]=ans;
            }
          
        }
        return dp[0][0];

    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        int ans=solvetab(text1,text2);
        return ans;
    }
};