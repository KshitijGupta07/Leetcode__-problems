class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        while(j<nums.size()-1){
            if(nums[j]==nums[j+1]){
                nums[i]=nums[j];
                j++;
            }
            else{
                nums[i]=nums[j];
                i++;
                j++;
            }
        }
        nums[i]=nums[j];
        return i+1;
    }
};