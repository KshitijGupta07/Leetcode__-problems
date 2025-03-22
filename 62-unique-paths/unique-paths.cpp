class Solution {
public:
   int solve(int r,int c,int m,int n,vector<vector<int>>&dp){
    if(r==m-1&&c==n-1){
        return 1;
    }
    if(r>=m||c>=n){
        return 0;
    }
    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    int down=solve(r,c+1,m,n,dp);
    int right=solve(r+1,c,m,n,dp);
    return dp[r][c]=down+right;
   }
   int tab(int m,int n){
     vector<vector<int>>dp(m,vector<int>(n,0));
     dp[m-1][n-1]=1;
     for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==m-1&&j==n-1){
                dp[i][j]=1;
            }
            else if(i+1<m&&j+1<n){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
            else if(i+1<m){
                dp[i][j]=dp[i+1][j];
            }
            else if(j+1<n){
                dp[i][j]=dp[i][j+1];
            }
        }
     }
     return dp[0][0];

   }
    int uniquePaths(int m, int n) {
        int r=0;
        int c=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=solve(r,c,m,n,dp);
        int ans2=tab(m,n);
        
        return ans2;
    }
};