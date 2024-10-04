class Solution {
public:
   bool check(string& s,int start,int end){
    
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
   }
   int solve(string& s,int index,vector<int>&dp){
     if(index>=s.length()){
        return 0;
     }
     if(dp[index]!=-1){
        return dp[index];
     }
     int ans=INT_MAX;
     for(int i=index;i<s.length();i++){
            
             if(check(s,index,i)){
                
                ans=min(ans,1+solve(s,i+1,dp));
             }
     }
    dp[index]=ans;
    return dp[index];
   }
   
    int minCut(string s) {
        int index=0;
        vector<int>dp(s.length(),-1);
        int ans=solve(s,index,dp);
        
        return ans-1;
    }
};