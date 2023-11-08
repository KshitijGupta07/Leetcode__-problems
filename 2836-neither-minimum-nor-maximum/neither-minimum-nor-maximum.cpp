class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
       /* sort(nums.begin(),nums.end());
        if(nums.size()<3){
            return -1;
        }
        if(nums[nums.size()-1]==nums[nums.size()-2]){
            return -1;
        }
        return nums[nums.size()-2];
        */
        int minimum=nums[0];
        int maximum=nums[0];
        for(int i=1;i<nums.size();i++){
            minimum=min(nums[i],minimum);
            maximum=max(nums[i],maximum);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=minimum&&nums[i]!=maximum){
                return nums[i];
                break;
            }
        }
        return -1;

    }
};