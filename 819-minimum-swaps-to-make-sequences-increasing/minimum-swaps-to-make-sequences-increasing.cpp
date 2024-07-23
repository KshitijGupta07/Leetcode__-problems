class Solution {
public:
   int solve(vector<int>&nums1,vector<int>&nums2,int index,bool swapped,vector<vector<int>>&dp){
    if(index>=nums1.size()){
        return 0;
    }
    if(dp[index][swapped]!=-1){
        return dp[index][swapped];
    }
    int prev1=nums1[index-1];
    int prev2=nums2[index-1];
    int ans=INT_MAX;
    if(swapped){
        swap(prev1,prev2);
    }
    //not swap

    if(nums1[index]>prev1&&nums2[index]>prev2){
        ans=solve(nums1,nums2,index+1,0,dp);
    }
    // swap agar karna hai
    if(nums1[index]>prev2&&nums2[index]>prev1){
        ans=min(ans,1+solve(nums1,nums2,index+1,1,dp));
    }
    dp[index][swapped]=ans;
    return dp[index][swapped];

    
   }
   int solvetab(vector<int>&nums1,vector<int>&nums2){
    int n=nums1.size();
     int sw=0;
     int noswap=0;
     int currswap=0;
     int nocurrswap=0;

      
     for(int i=n-1;i>=1;i--){
      
             
        for(int j=1;j>=0;j--){
              int prev1=nums1[i-1];
        int prev2=nums2[i-1];
            int ans=INT_MAX;
            if(j==1){
               swap(prev1,prev2);
            }
            if(nums1[i]>prev1&&nums2[i]>prev2){
               ans=noswap;
            }
            if(nums1[i]>prev2&&nums2[i]>prev1){
                ans=min(ans,1+sw);
            }
            if(j==1){
                currswap=ans;
            }
            else{
                nocurrswap=ans;
            }
        }
       sw=currswap;
       noswap=nocurrswap;
        
     }
    return min(sw,noswap);

   }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        bool swapped=0;
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n=nums1.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
       int ans=solve(nums1,nums2,1,swapped,dp); 
       return solvetab(nums1,nums2);
    }
};