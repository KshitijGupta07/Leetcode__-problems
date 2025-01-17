class Solution {
public:
    long long solve(vector<int>&A,vector<int>&B,int i,int c,vector<vector<long long >>&dp){
        if(i>=A.size()){
            return 0;
        }
        if(dp[i][c]!=-1){
            return dp[i][c];
        }
        long long a=0;
        
        if(c==0)
        a=A[i]+max(solve(A,B,i+1,c,dp),solve(A,B,i+2,1-c,dp));
        else{
            a=B[i]+max(solve(A,B,i+1,c,dp),solve(A,B,i+2,1-c,dp));
        }
        return dp[i][c]=a;


    }
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        int i=0;
        vector<vector<long long >>dp(A.size(),vector<long long >(2,-1));
        long long ans=max(solve(A,B,i,0,dp),solve(A,B,i,1,dp));
        return ans;
    }
};