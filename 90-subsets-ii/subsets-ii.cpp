class Solution {
public:
   void solve(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,int index){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(nums,temp,ans,index+1);
        while(index+1<nums.size()&&nums[index]==nums[index+1]){index++;}
        temp.pop_back();
        solve(nums,temp,ans,index+1);
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(nums,temp,ans,0);
        return ans;
    }
};