class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    
        int r=0;
        int count=0;
        int ans=0;
        while(r<nums.size()){
             if(nums[r]==1){
                count++;
                
             } 
             else{
                ans=max(ans,count);
                count=0;
             }
             r++;
        }
        return max(ans,count);
    }
};