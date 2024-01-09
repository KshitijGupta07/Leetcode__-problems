class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int min=nums[1]-nums[0];
        for(int i=2;i<nums.size();i++){
            if(min>nums[i]-nums[i-1]){
                min=nums[i]-nums[i-1];
            }
        }
        return min;
    }
};