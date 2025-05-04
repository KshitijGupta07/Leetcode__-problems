class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans=1;
        int max=nums[0];
        for(int i=1;i<nums.size();i++){
             if(nums[i]>=max){
                max=nums[i];
                ans++;
             }
        }
        return ans;
    }
};