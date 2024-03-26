class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int element=nums[i];
            nums[abs(element)-1]=-nums[abs(element)-1];
            if(nums[abs(element)-1]>0){
                ans.push_back(abs(element));
            }
        }
        return ans;

    }
};