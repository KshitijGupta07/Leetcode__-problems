class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            int element=abs(nums[i]);
            nums[element-1]=-nums[element-1];
            if(nums[element-1]>0){
                  return element;
            }
        }
        return -1;
    }
};