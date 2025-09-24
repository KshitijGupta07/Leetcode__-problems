class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int target=-nums[i];
            int start=i+1;
            int end=nums.size()-1;
              while(start<end){
                 while(start!=i+1&&start<nums.size()&&nums[start]==nums[start-1]){
                     start++;
                 }
                 while(end!=nums.size()-1&&end>=0&&nums[end]==nums[end+1]){
                    end--;
                 }
                 if(start>=end){
                    break;
                 }
                if(nums[start]+nums[end]==target){
                     ans.push_back({nums[i],nums[start],nums[end]});
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
        }
        return ans;
    }
};