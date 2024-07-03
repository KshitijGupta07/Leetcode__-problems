class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=4){
            return 0;
        }
        int mini=INT_MAX;
        int count=3;
        for(int i=nums.size()-1;i>=nums.size()-4;i--){
             mini=min(mini,nums[i]-nums[count]);
             count=count-1;
        }
        return mini;

    }
};