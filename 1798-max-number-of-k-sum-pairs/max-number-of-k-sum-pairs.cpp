class Solution {
public:
    int maxOperations(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int count=0;
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            if(nums[start]+nums[end]==target){
                count++;
                start++;
                end--;
            }
            else if(nums[start]+nums[end]>target){
                end--;
            }
            else{
                start++;
            }
        }
        return count;
    }
};