class Solution {
public:
   int solve(vector<vector<int>>&coins,int i,int j,int count,vector<vector<vector<int>>>&dp){
     if(i>=coins.size()||j>=coins[0].size()){
        return -1000000;
    }
    cout<<i<<j<<count<<endl;
    
    if(i==coins.size()-1&&j==coins[0].size()-1){
        if(coins[i][j]<0){
            if(count<2){
            
            return 0;
            }
            else{
                return coins[i][j];
            }
        }
        return coins[i][j];
     }
      if(dp[i][j][count]!=-1000000){
        return dp[i][j][count];
    }
    
    
    int l=INT_MIN;

    int r=INT_MIN;
    if(coins[i][j]<0){
        if(count<2){
            l=solve(coins,i,j+1,count+1,dp);
            r=solve(coins,i+1,j,count+1,dp);
        }
        l=max(l,coins[i][j]+solve(coins,i,j+1,count,dp));
        r=max(r,coins[i][j]+solve(coins,i+1,j,count,dp));

    }
    else{
        l=coins[i][j]+solve(coins,i,j+1,count,dp);
        r=coins[i][j]+solve(coins,i+1,j,count,dp);
    }

     
    
     
   
     return dp[i][j][count]=max(l,r);
     
   }
     int tab(vector<vector<int>>&coins){
          vector<vector<vector<int>>>dp(coins.size(),vector<vector<int>>(coins[0].size(),vector<int>(3,-1000000)));
          dp[0][0][0]=coins[0][0];
          int m=coins.size()-1;
          int n=coins[0].size()-1;
          
          if(coins[0][0]<0){
            dp[0][0][1]=0;
            dp[0][0][2]=0;
          }
          else{
            dp[0][0][1]=coins[0][0];
            dp[0][0][2]=coins[0][0];
          }
          for(int i=0;i<coins.size();i++){
            for(int j=0;j<coins[0].size();j++){
                for(int k=0;k<3;k++){
                    if(i==0&&j==0){
                        continue;
                    }
                    if(i>0){
                        dp[i][j][k]=max(dp[i][j][k],coins[i][j]+dp[i-1][j][k]);
                        if(coins[i][j]<0&&k>0){
                            dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]);
                        }
                    }
                    if(j>0){
                        dp[i][j][k]=max(dp[i][j][k],coins[i][j]+dp[i][j-1][k]);
                        if(coins[i][j]<0&&k>0){
                            dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]);
                        }
                    }
                }
            }
          }
          return max(dp[m][n][0],max(dp[m][n][1],dp[m][n][2]));
     }
    int maximumAmount(vector<vector<int>>& coins) {
        int count=0;
        int m=coins.size()-1;
        int n=coins[0].size()-1;
        vector<vector<vector<int>>>dp(coins.size(),vector<vector<int>>(coins[0].size(),vector<int>(3,-1000000)));
        int ans=tab(coins);
        
        return ans;
    }
};