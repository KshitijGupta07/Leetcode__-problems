class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
               int a=abs(nums[i])-1;
               nums[a]=-nums[a];
               if(nums[a]>0){
                return a+1;
               }
        }
        return -1;
    }
};