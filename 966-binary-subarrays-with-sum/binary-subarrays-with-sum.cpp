class Solution {
public:
   int calculate(vector<int>&nums,int goal){
         int sum=0;
        int l=0;
        int r=0;
        int count=0;
        while(r<nums.size()){
            sum+=nums[r];
            if(sum>goal){
                while(sum>goal&&l<=r){
                    cout<<sum<<" ";
                sum=sum-nums[l];
                l++;
                }
            }
    
             
             count+=r-l+1;
             r++;
            
        }
        return count;
   }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return calculate(nums,goal)-calculate(nums,goal-1);
    }
};