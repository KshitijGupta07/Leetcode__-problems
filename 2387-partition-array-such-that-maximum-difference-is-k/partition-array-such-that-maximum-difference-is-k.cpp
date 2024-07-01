class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=1;
        int left=0;
        int right=0;
        while(right<nums.size()){
            if(nums[right]-nums[left]>k){
                left=right;
                count++;
            }
            else{
            right=right+1;
            }
        }
        return count;
    }
};