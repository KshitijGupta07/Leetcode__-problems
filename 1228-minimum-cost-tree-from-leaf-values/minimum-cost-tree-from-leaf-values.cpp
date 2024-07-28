class Solution {
public:
   int solve(vector<int>&arr,int start,int end,map<pair<int,int>,int>&m,vector<vector<int>>&dp){
    if(start>=end){
        return 0;

    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    int ans=INT_MAX;
    for(int i=start;i<end;i++){
        ans=min(ans,m[{start,i}]*m[{i+1,end}]+solve(arr,start,i,m,dp)+solve(arr,i+1,end,m,dp));
    }
    dp[start][end]=ans;
    return dp[start][end];

   }
   int solvetab(vector<int>&arr,map<pair<int,int>,int>&m){
    vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),0));
    for(int i=0;i<arr.size();i++){
        dp[i][i]=0;
    }
    for(int start=0;start<arr.size();start++){
        for(int end=arr.size()-1;end>start;end--){
            int ans=INT_MAX;
            for(int i=start;i<end;i++){
                 ans=min(ans,m[{start,i}]*m[{i+1,end}]+dp[start][i]+dp[i+1][end]);
            }
            dp[start][end]=ans;
            cout<<dp[start][end]<<" ";
        }
    }
    return dp[0][arr.size()-1];
   }
    int mctFromLeafValues(vector<int>& arr) {
       map<pair<int,int>,int>m;
       vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
       for(int i=0;i<arr.size();i++){
           m[{i,i}]=arr[i];
           for(int j=i+1;j<arr.size();j++){
            m[{i,j}]=max(arr[j],m[{i,j-1}]);
           }
       } 
       int start=0;
       int end=arr.size()-1;
       int ans=solve(arr,start,end,m,dp);
       return solve(arr,start,end,m,dp);

    }
};