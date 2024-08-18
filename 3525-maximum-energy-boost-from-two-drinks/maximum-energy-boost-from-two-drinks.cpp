class Solution {
public:
  long long solve(vector<int>& energyDrinkA, vector<int>& energyDrinkB,int index,int curr,vector<vector<long long>>&dp){
    if(index>=energyDrinkA.size()){
        return 0;
    }
    long long ans=0;
    if(dp[index][curr]!=-1){
        return dp[index][curr];
    }
    if(curr==1){
           ans=max(ans,energyDrinkA[index]+solve(energyDrinkA,energyDrinkB,index+1,1,dp));
    } 
    else{
        ans=max(ans,energyDrinkB[index]+solve(energyDrinkA,energyDrinkB,index+1,0,dp));
    }
    ans=max(ans,solve(energyDrinkA,energyDrinkB,index+1,1-curr,dp));
    dp[index][curr]=ans;
    return dp[index][curr];
    
  }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        long long ans=0;
        int n=energyDrinkA.size();
        int index=0;
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        ans=max(solve(energyDrinkA,energyDrinkB,0,0,dp),solve(energyDrinkA,energyDrinkB,0,1,dp));
        return ans;

    }
};