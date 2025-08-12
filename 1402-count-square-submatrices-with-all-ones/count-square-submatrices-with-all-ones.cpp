class Solution {
public:
    int solve(vector<vector<int>>&matrix,int i,int j,map<pair<int,int>,bool>&m,vector<vector<int>>&dp){
        if(i>=matrix.size()||j>=matrix[0].size()||matrix[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int x=solve(matrix,i+1,j,m,dp)+1;
        int y=solve(matrix,i,j+1,m,dp)+1;
        int z=solve(matrix,i+1,j+1,m,dp)+1;
        return dp[i][j]=min(x,min(y,z));
    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        map<pair<int,int>,bool>m;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1&&m[{i,j}]==false){
                    int a=solve(matrix,i,j,m,dp);
                    cout<<a<<endl;
                    ans=ans+a;
                }
            }
        }
        return ans;
    }
};