class Solution {
public:
     int solve(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp){
        
        if(i==matrix.size()-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans1=INT_MAX;
        int ans2=INT_MAX;
        int ans3=INT_MAX;
         if(j+1<matrix.size()){
        ans1=matrix[i][j]+solve(matrix,i+1,j+1,dp);
         }
         if(j-1>=0){
        ans2=matrix[i][j]+solve(matrix,i+1,j-1,dp);
         }
         
        ans3=matrix[i][j]+solve(matrix,i+1,j,dp);
         return dp[i][j]=min(ans1,min(ans2,ans3));
     }
     int tab(vector<vector<int>>&matrix){
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix.size(),0));
         dp.back()=matrix.back();
        for(int i=matrix.size()-2;i>=0;i--){

            
            for(int j=0;j<matrix.size();j++){
                int x=INT_MAX;
                if(j-1>=0){
                    x=min(x,matrix[i][j]+dp[i+1][j-1]);
                }
             if(j+1<matrix.size()){
                    x=min(x,matrix[i][j]+dp[i+1][j+1]);
                }
                x=min(x,matrix[i][j]+dp[i+1][j]);
                dp[i][j]=x;
            }
        }
        int maxi=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            maxi=min(maxi,dp[0][i]);
        }
        return maxi;
     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        // vector<vector<int>>dp(matrix.size(),vector<int>(matrix.size(),-1));
        // for(int i=0;i<matrix.size();i++){
        //     ans=min(ans,solve(matrix,0,i,dp));
        // }
        return tab(matrix);
    }
};