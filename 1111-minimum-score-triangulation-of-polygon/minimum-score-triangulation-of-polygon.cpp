class Solution {
public:
    int solve(vector<int>&values,int start ,int end,vector<vector<int>>&dp){
        if(start+1==end){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int ans=INT_MAX;
        for(int i=start+1;i<end;i++){
             ans=min(ans,values[start]*values[end]*values[i]+solve(values,start,i,dp)+solve(values,i,end,dp));
            
        }
       dp[start][end]=ans;
        return dp[start][end];
    }
    int tabsolve(vector<int>&values){
        vector<vector<int>>dp(values.size(),vector<int>(values.size(),0));
        for(int i=values.size()-1;i>=0;i--){
            for(int j=i+2;j<values.size();j++){
                int ans=INT_MAX;
                for(int k=i+1;k<j;k++){
                    ans=min(ans,values[i]*values[j]*values[k]+dp[i][k]+dp[k][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][values.size()-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        int start=0;
        int end=values.size()-1;
        vector<vector<int>>dp(end+1,vector<int>(end+1,-1));
        // int ans= solve(values,start,end,dp);
        int ans=tabsolve(values);
        return ans;
    }
};