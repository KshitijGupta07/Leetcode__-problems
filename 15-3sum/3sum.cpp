class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int start=i+1;
            int end=nums.size()-1;
            int target=nums[i];
            while(start<end){
                if(start>i+1&&nums[start]==nums[start-1]){
                    start++;
                    continue;
                }
                if(end<nums.size()-1&&nums[end]==nums[end+1]){
                    end--;
                    continue;
                }
                else if(nums[start]+nums[end]+target==0){
                         ans.push_back({target,nums[start],nums[end]});
                         end--;
                         start++;
                 }
                 else if(nums[start]+nums[end]+target>0){
                    end--;
                 }
                 else{
                    start++;
                 }
            }
        }
        return ans;
    }
};