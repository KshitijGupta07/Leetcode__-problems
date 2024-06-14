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
    for(int i=1;i<=n;i++){
        
        if(i-2<0){
            incl=nums[i];
            excl=dp[i-1];

        }
        else{
            incl=dp[i-2]+nums[i];
            excl=dp[i-1];
        }
        cout<<incl<<" "<<excl<<endl;
        dp[i]=max(incl,excl);
    }
    return dp[n];
   }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        // vector<int>dp(n+1,-1);
        int ans=bottomup(nums,n);
        return ans;
    }
};