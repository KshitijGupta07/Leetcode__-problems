class Solution {
public:
   long long solve(vector<int>&a,vector<int>&b,int i,int j,vector<vector<long long >>&dp){
     if(i>=4){
        return 0;
     }
     if(j>=b.size()){
        return INT_MIN;
     }
     if(dp[i][j]!=-1){
        return dp[i][j];
     }
     long long element1=a[i];
     long long element2=b[j];
      long long include=element1*element2+solve(a,b,i+1,j+1,dp);
      long long exclude=solve(a,b,i,j+1,dp);
      dp[i][j]=max(include,exclude);
      return dp[i][j];
   }
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long >>dp(4,vector<long long >(b.size(),-1));
       long long ans=solve(a,b,0,0,dp);
       return ans; 
    }
};