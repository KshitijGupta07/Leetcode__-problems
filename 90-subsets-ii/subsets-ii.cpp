class Solution {
public:
   void solve(vector<vector<int>>&ans,vector<int>temp,vector<int>&nums,int i){
    if(i>=nums.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    solve(ans,temp,nums,i+1);
   
    
     while(i+1<nums.size()&&nums[i]==nums[i+1]){
        i++;
    }
    temp.pop_back();
    solve(ans,temp,nums,i+1);
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,nums,i);
        return ans;
    }
};