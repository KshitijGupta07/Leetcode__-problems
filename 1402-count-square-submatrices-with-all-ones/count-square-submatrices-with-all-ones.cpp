class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            dp[i][0]=matrix[i][0];
        }
        for(int j=0;j<matrix[0].size();j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        int ans=0;
        for(auto j:dp){
            for(auto k:j){
                ans+=k;
            }
        }
        return ans;
    }
};