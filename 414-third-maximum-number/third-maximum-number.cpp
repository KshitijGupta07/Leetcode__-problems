class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1){
            return nums[0];
        }
        for(int i=0;i<nums.size()-1;){
            if(nums[i]==nums[i+1]){
                nums.erase(nums.begin()+i+1);
            }
            else{
                i++;
            }
        }
        if(nums.size()>=3){
            return nums[nums.size()-3];
        }
        return nums[1];
    }
};