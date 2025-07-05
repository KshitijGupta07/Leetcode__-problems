class Solution {
public:
   long long solve(int m,int n,long long  i,long long  j,vector<vector<int>>&waitCost,int time,vector<vector<vector<long long >>>&dp){
    long long ans=pow(2,40);
      if(i==m-1&&j==n-1){
          return m*n;
      }
      if(dp[i][j][time%2]!=-1){
        return dp[i][j][time%2];
      }
        if(time%2==1){
            long long left=0;
            long long right=0;
            if(j+1<n){
                  left=(i+(long long )1)*(j+(long long )1)+solve(m,n,i,j+1,waitCost,time+1,dp);
            }
            else{
                left=pow(2,40);
            }
            if(i+1<m){
                    right=(i+(long long )1)*(j+(long long )1)+solve(m,n,i+1,j,waitCost,time+1,dp);
            }
            else{
                right=pow(2,40);
            }
            ans=min(left,right);
        }
        else{
            long long element=waitCost[i][j];
            ans=min(ans,element+solve(m,n,i,j,waitCost,time+1,dp));
        }
        return dp[i][j][time%2]=ans;
   }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<vector<long long >>>dp(m,vector<vector<long long>>(n,vector<long long>(2,-1)));
        long long ans=solve(m,n,0,0,waitCost,1,dp);
        return ans;
    }
};