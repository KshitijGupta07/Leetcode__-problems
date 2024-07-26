class Solution {
public:
    int solve(string word1,string word2,int i,int j,vector<vector<int>>&dp){
        if(i==word1.length()){
            return word2.length()-j;
        }
        if(j==word2.length()){
            return word1.length()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(word1[i]==word2[j]){
            ans=solve(word1,word2,i+1,j+1,dp);
        }
        else{
            int insert=1+solve(word1,word2,i,j+1,dp);
            int erase=1+solve(word1,word2,i+1,j,dp);
            int  replace=1+solve(word1,word2,i+1,j+1,dp);
            ans=min(insert,min(erase,replace));
            
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int solvetab(string word1,string word2){
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,0));
          for(int i=0;i<word2.length();i++){
            dp[word1.length()][i]=word2.length()-i;
          }
          for(int j=0;j<word1.length();j++){
            dp[j][word2.length()]=word1.length()-j;
          }
          for(int i=word1.length()-1;i>=0;i--){
            for(int j=word2.length()-1;j>=0;j--){
                int ans=0;
                if(word1[i]==word2[j]){
                    ans=dp[i+1][j+1];
                }
                else{
                    int insert=1+dp[i][j+1];
                    int erase=1+dp[i+1][j];
                    int replace=1+dp[i+1][j+1];
                    ans=min(insert,min(erase,replace));
                    
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
        return solvetab(word1,word2);
    }
};