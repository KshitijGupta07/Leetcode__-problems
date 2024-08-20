class Solution {
public:
  int solve(vector<int>&piles,vector<int>&suffix,int index,int m,vector<vector<int>>&dp){
    
    if(index+2*m>=piles.size()){
        return suffix[index];
    }
    if(dp[index][m]!=-1){
        return dp[index][m];
    }
    int ans=INT_MAX;
    for(int i=1;i<=2*m;i++){
           ans=min(ans,solve(piles,suffix,i+index,max(i,m),dp));
    }
    return dp[index][m]=suffix[index]-ans;
  }
    int stoneGameII(vector<int>& piles) {
        if(piles.size()==1){
            return piles[0];
        }
        vector<int>suffix;
        int element=0;
        int index=0;
        for(int i=piles.size()-1;i>=0;i--){
              element+=piles[i];
              suffix.push_back(element);
        }
        reverse(suffix.begin(),suffix.end());
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size()*2,-1));
        return solve(piles,suffix,index,1,dp);
    }
};