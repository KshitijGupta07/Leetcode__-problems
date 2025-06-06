class Solution {
public:
   bool solve(vector<int>&stones,int i,int k,map<int,int>&m,vector<vector<int>>&dp){
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
        a= solve(stones,m[stones[i]+k-1],k-1,m,dp);
      }
      if(m.find(stones[i]+k)!=m.end()){
        b= solve(stones,m[stones[i]+k],k,m,dp);
      }
      if(m.find(stones[i]+k+1)!=m.end()){
        c= solve(stones,m[stones[i]+k+1],k+1,m,dp);
      }

      return dp[i][k]=a||b||c;
     
     
         
   }
    bool canCross(vector<int>& stones) {
    if(stones[1]!=1){
            return false;
        }
        int last =0;
        map<int,int>m;
        for(int i =1;i<stones.size();i++){
            m[stones[i]]=i;
        }
        vector<vector<int>>dp(stones.size(),vector<int>(stones.size(),-1));
        bool ans=solve(stones,1,1,m,dp);
        return ans;
    }
};