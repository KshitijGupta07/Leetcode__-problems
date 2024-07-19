class Solution {
public:
    int solve(vector<vector<char>> &matrix,int i,int j,int& maxi,vector<vector<int>>&dp){
        if(i>=matrix.size()||j>=matrix[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solve(matrix,i,j+1,maxi,dp);
        int diagonal=solve(matrix,i+1,j+1,maxi,dp);
        int down=solve(matrix,i+1,j,maxi,dp);
    
           if(matrix[i][j]=='1'){
             int ans=1+min(right,min(down,diagonal));
               maxi=max(maxi,ans);
               dp[i][j]=ans;
               return dp[i][j];
           }
           else{
            return 0;
           }
       
         
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
       vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int ans=solve(matrix,0,0,maxi,dp);
        return maxi*maxi;
    }
};