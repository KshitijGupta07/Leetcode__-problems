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
             while(start<end){
                while(start-1>i&&start<nums.size()&&nums[start]==nums[start-1]){
                    start++;
                }
                while(end+1<nums.size()-1&&end>=0&&nums[end]==nums[end+1]){
                    end--;
                }
                if(start<end){
                if(nums[start]+nums[end]+nums[i]==0){
                    ans.push_back({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                }
                else if(nums[start]+nums[end]+nums[i]>0){
                    end--;
                }
                else{
                    start++;
                }
                }
             }
             
        }
        return ans;
    }
    

};