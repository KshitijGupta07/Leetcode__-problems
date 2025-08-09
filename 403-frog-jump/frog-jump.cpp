class Solution {
public:
   bool solve(vector<int>&stones,map<int,int>&m,int i,int k,vector<vector<int>>&dp){
    if(i==stones.size()-1){
        return true;
    }
    
    if(dp[i][k]!=-1){
        return dp[i][k];
    }
    bool a=false;
    bool b=false;
    bool c=false;
      if(k-1>0&&m.find(stones[i]+k-1)!=m.end()){
        a=solve(stones,m,m[stones[i]+k-1],k-1,dp);
      }
      if(m.find(stones[i]+k)!=m.end()){
        b=solve(stones,m,m[stones[i]+k],k,dp);
      }
      if(m.find(stones[i]+k+1)!=m.end()){
        c=solve(stones,m,m[stones[i]+k+1],k+1,dp);
      }
      return dp[i][k]=a||b||c;
   }
    bool canCross(vector<int>& stones) {
        if(stones[1]>1){
            return false;
        }
        map<int,int>m;
        int count=0;
        for(auto j:stones){
            m[j]=count;
            count++;
        }
        vector<vector<int>>dp(stones.size(),vector<int>(stones.size(),-1));
        int i=0;
        bool ans=solve(stones,m,1,1,dp);
        return ans;
    }
};