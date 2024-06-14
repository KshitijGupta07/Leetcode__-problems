class Solution {
public:
//    int solve(vector<int>&nums,int n,vector<int>&dp){
//        if(n==0){
//         return nums[0];
//        }
//        if(n<0){
//         return 0;
//        }
//        if(dp[n]!=-1){
//         return dp[n];
//        }
//        int incl=solve(nums,n-2,dp)+nums[n];
//        int excl=solve(nums,n-1,dp);
//        dp[n]=max(incl,excl);
//        return dp[n];
//    }
   int bottomup(vector<int>&nums,int n){
    if(n<0){
        return 0;
    }
    
    vector<int>dp(n+1,0);
    dp[0]=nums[0];
    int incl=0;
    int excl=0;
    bool check=false;
    bool c=false;
    for(int i=1;i<=n-1;i++){
        
        if(i-2<0){
            incl=nums[i];
            excl=dp[i-1];

        }
        else{
            
            incl=dp[i-2]+nums[i];
            excl=dp[i-1];
            
        }
        
         
        dp[i]=max(incl,excl);
         
    }
    
    return dp[n-1];
   }
   int bottomup2(vector<int>&nums,int n){
      if(n<0){
        return 0;
    }
    
    vector<int>dp(n+1,0);
    dp[1]=nums[1];
    int incl=0;
    int excl=0;
    bool check=false;
    bool c=false;
    for(int i=2;i<=n;i++){
        
              
            
            incl=dp[i-2]+nums[i];
            excl=dp[i-1];
            
        
        
         
        dp[i]=max(incl,excl);
         
    }
    
    return dp[n];
   }
   
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        if(n==0){
            return nums[0];
        }
        if(n==1){
            return max(nums[0],nums[1]);
        }
        // vector<int>dp(n+1,-1);
        int ans=bottomup(nums,n);
        int ans2=bottomup2(nums,n);
        return max(ans,ans2);
    }
};