class Solution {
public:

    int smallestRangeI(vector<int>& nums, int k) {
       int minimum=nums[0];
       int maximum=nums[0];
       for(int i=1;i<nums.size();i++){
         maximum=max(maximum,nums[i]);
         minimum=min(minimum,nums[i]);
       } 
       int d=maximum-minimum;
       if(d-k<=k){
         return 0;
       }
       return d-k-k;
    }
};