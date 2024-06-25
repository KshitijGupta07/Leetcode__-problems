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
    int tab(vector<int>&days,vector<int>&costs){
        vector<int>dp(days.size(),-1);
        dp[days.size()-1]=0;
        int i=0;
        int option=0;
        int option2=0;
        int option3=0;
        for( i=days.size()-2;i>=0;i--){
        int option=costs[0]+dp[i+1];
        for(int index=i;index<days.size()&&days[index]<days[i]+7;index++){
               int option2=costs[1]+dp[index];
        }
       
        for(int index=i;i<days.size()&&days[index]+days[i]+30;index++){
               int option3=costs[2]+dp[index];
        }
        
        dp[i]=min(option,min(option2,option3));
    }
        return dp[0];
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
        int index=0;
        int ans=solve(days,costs,index,dp);
        return ans;
    }
};