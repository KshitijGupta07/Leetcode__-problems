class Solution {
public:
    bool solve(vector<vector<char>>&grid,int i,int j,int k,vector<vector<vector<int>>>&dp){
        if(i>=grid.size()||j>=grid[0].size()){
            return false;
        }
         if(grid[i][j]=='('){
            k++;
        }
        if(grid[i][j]==')'){
            k--;
        }
         if(k<0){
            return false;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        if(i==grid.size()-1&&j==grid[0].size()-1){
            if(k==0){
                return true;
            }
            else{
                return false;
            }
        }
       
        return dp[i][j][k]=solve(grid,i+1,j,k,dp)|solve(grid,i,j+1,k,dp);
        
       
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        vector<vector<vector<int>>>dp(101,vector<vector<int>>(101,vector<int>(205,-1)));
        bool ans=solve(grid,0,0,0,dp);
        return ans;
    }
};