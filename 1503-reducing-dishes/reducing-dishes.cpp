class Solution {
public:
     int solve(vector<int>& satisfaction,int index,int count,vector<vector<int>>&dp){
    if(index>=satisfaction.size()){
        return 0;
    }
    if(dp[index][count]!=0){
        return dp[index][count];
    }
    int include=satisfaction[index]*(count+1)+solve(satisfaction,index+1,count+1,dp);
    int exclude=solve(satisfaction,index+1,count,dp);
    
     int ans=max(exclude,include);
     dp[index][count]=ans;
     return dp[index][count];
   }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int index=0;

        int count=0;
        vector<vector<int>>dp(satisfaction.size(),vector<int>(satisfaction.size(),0));
        int ans=solve(satisfaction,index,count,dp);
        return ans;
    }
};