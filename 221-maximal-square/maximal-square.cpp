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
    int solvetab(vector<vector<char>>&matrix,int &maxi){
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
    
       for(int i=matrix.size()-1;i>=0;i--){
        for(int j=matrix[0].size()-1;j>=0;j--){
            int right=dp[i][j+1];
            int diagonal=dp[i+1][j+1];
            int bottom=dp[i+1][j];
            if(matrix[i][j]=='1'){
            int ans=1+min(right,min(diagonal,bottom));
            dp[i][j]=ans;
            maxi=max(maxi,ans);
            }
            else{
                dp[i][j]=0;
            }
        }
       }
       return dp[0][0];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
       vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int ans=solvetab(matrix,maxi);
        return maxi*maxi;
    }
};