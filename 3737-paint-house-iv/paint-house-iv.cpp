class Solution {
public:
    long long solve(int n,int i,int left,int right,vector<vector<int>>&cost,vector<vector<vector<long long>>>&dp){
       if(i>=n/2){
        return 0;
       }
       if(dp[i][left][right]!=-1){
        return dp[i][left][right];
       }
       long long ans=LONG_MAX;
       for(int c=0;c<3;c++){
            if(c!=left){
                for(int d=0;d<3;d++){
                    if(d!=right&&d!=c){
                       ans=min(ans,cost[i][c]+cost[n-i-1][d]+solve(n,i+1,c,d,cost,dp));
                    }
                }
            }
       }
       return dp[i][left][right]=ans;
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<long long>>>dp(cost.size(),vector<vector<long long >>(4,vector<long long>(4,-1)));
        long long ans=solve(n,0,3,3,cost,dp);
        return ans;
    }
};