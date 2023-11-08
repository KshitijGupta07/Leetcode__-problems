class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<3){
            return -1;
        }
        if(nums[nums.size()-1]==nums[nums.size()-2]){
            return -1;
        }
        return nums[nums.size()-2];
    }
};