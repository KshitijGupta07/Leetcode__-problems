class Solution {
public:
     int solve(int index,vector<int>&rating,int count,vector<vector<int>>&dp){
        
        if(count==3){
            return 1;
            
        }
        if(dp[index][count]!=-1){
            return dp[index][count];
        }
        int a=0;
        for(int idx=index+1;idx<rating.size();idx++){
            if(rating[index]<rating[idx]){
                a+=solve(idx,rating,count+1,dp);
            }
        }
        
        dp[index][count]=a;
        return dp[index][count];
     }
     int solve2(int index,vector<int>&rating,int count,vector<vector<int>>&dp){
        if(count==3){
            return 1;
        }
        if(dp[index][count]!=-1){
            return dp[index][count];
        }
        int a=0;
        for(int idx=index+1;idx<rating.size();idx++){
             if(rating[index]>rating[idx]){
                a+=solve2(idx,rating,count+1,dp);
            }
        }
        
        
        dp[index][count]=a;
        return dp[index][count];
     }

    int numTeams(vector<int>& rating) {
        int inc=0;
        vector<vector<int>>dp(rating.size(),vector<int>(4,-1));
        vector<vector<int>>dp2(rating.size(),vector<int>(4,-1));
        for(int i=0;i<rating.size();i++){
            inc+=solve(i,rating,1,dp);
            inc+=solve2(i,rating,1,dp2);
        }
        
        
        return inc;
    }
};