class Solution {
public:
   int solve(int index,int end,vector<int>&slices,int n,vector<vector<int>>&dp){
    if(n==0||index>end){
        return 0;
    }
    if(dp[index][n]!=-1){
        return dp[index][n];
    }
    int include=slices[index]+solve(index+2,end,slices,n-1,dp);
    int exclude=solve(index+1,end,slices,n,dp);
    dp[index][n]=max(include,exclude);
    return dp[index][n];
   }
    int maxSizeSlices(vector<int>& slices) {
        
        int n=slices.size();
        vector<vector<int>>dp(slices.size(),vector<int>(n/3 +1,-1));
        vector<vector<int>>dp1(slices.size(),vector<int>(n/3 +1,-1));
       int first=solve(0,n-2,slices,n/3,dp);
       int second=solve(1,n-1,slices,n/3,dp1); 
       return max(first,second);
    }
};