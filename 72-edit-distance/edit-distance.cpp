class Solution {
public:
    int solve(string word1,string word2,int i,int j,vector<vector<int>>&dp){
        if(i>=word1.length()){
            return word2.length()-j;
        }
        if(j>=word2.length()){
            return word1.length()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        if(word1[i]==word2[j]){
            ans=min(ans,solve(word1,word2,i+1,j+1,dp));
        }
        else{
            ans=min(ans,1+solve(word1,word2,i+1,j,dp));
            ans=min(ans,1+solve(word1,word2,i+1,j+1,dp));
            ans=min(ans,1+solve(word1,word2,i,j+1,dp));
        }
        return dp[i][j]=ans;

    }
    int tab(string word1,string word2){
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,0));
        for(int i=0;i<=word1.length();i++){
            dp[i][word2.length()]=word1.length()-i;
        }
        for(int j=0;j<=word2.length();j++){
            dp[word1.length()][j]=word2.length()-j;
        }
        for(int i=word1.length()-1;i>=0;i--){
            
            for(int j=word2.length()-1;j>=0;j--){
                int ans=INT_MAX;
                if(word1[i]==word2[j]){
                      ans=dp[i+1][j+1];
                }
                else{
                    ans=min(ans,1+dp[i+1][j]);
                    ans=min(ans,1+dp[i+1][j+1]);
                    ans=min(ans,1+dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
        
    }
    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        int ans=solve(word1,word2,i,j,dp);
        int ans2=tab(word1,word2);
        return ans2;
    }
};