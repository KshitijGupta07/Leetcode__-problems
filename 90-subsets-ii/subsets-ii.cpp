class Solution {
public:
   void solve(vector<int>temp,vector<vector<int>>&ans,int i,vector<int>&nums){
      if(i>=nums.size()){
        ans.push_back(temp);
        return;
      }
      temp.push_back(nums[i]);
      solve(temp,ans,i+1,nums);
      while(i+1<nums.size()&&nums[i]==nums[i+1]){
        i+=1;
      }
      temp.pop_back();
      solve(temp,ans,i+1,nums);
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        vector<int>temp;
        vector<vector<int>>ans;
        solve(temp,ans,i,nums);
        return ans;
    }
};