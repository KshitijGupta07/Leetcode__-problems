class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,int index,vector<int>&dp){
      if(index==days.size()){
        return 0;
      }
      if(dp[index]!=-1){
        return dp[index];
      }
      //1 day pass
      int option=costs[0]+solve(days,costs,index+1,dp);
      int i=0;
      //7 day pass
      for( i=index;i<days.size()&&days[i]<days[index]+7;i++);
      
      int option2=costs[1]+solve(days,costs,i,dp);

      //30 day pass
 for( i=index;i<days.size()&&days[i]<days[index]+30;i++);
      
      int option3=costs[2]+solve(days,costs,i,dp);

      dp[index]=min(option,min(option2,option3));
return dp[index];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
        int index=0;
        int ans=solve(days,costs,index,dp);
        return ans;
    }
};