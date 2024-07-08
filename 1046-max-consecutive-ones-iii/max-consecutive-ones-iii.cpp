class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int length=0;
        int maxlength=0;
        int count0=0;
        while(right<nums.size()){
            if(nums[right]==0){
                count0++;
            }
            if(count0<=k){
                length=right-left+1;
                maxlength=max(maxlength,length);
            }
            if(count0>k){
                if(nums[left]==0){
                    count0--;
                }
                left++;
            
            }
            right++;
        }
        return maxlength;
    }
};