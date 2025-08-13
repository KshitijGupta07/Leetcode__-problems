class Solution {
public:
   int solve(string  &word1,string &word2 ,int i,int j,vector<vector<int>>&dp){
    if(i>=word1.length()&&j>=word2.length()){
        return 0;
    }
    
    if(i>=word1.length()){
        cout<<j<<"y"<<endl;
        return word2.length()-j;
    }
    if(j>=word2.length()){
        cout<<i<<"x"<<endl;
        return word1.length()-i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(word1[i]==word2[j]){
        return dp[i][j]=solve(word1,word2,i+1,j+1,dp);
    }
    return  dp[i][j]=min(1+solve(word1,word2,i+1,j,dp),1+solve(word1,word2,i,j+1,dp));
   }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        int ans=solve(word1,word2,0,0,dp);
        return ans;
    }
};