class Solution {
public:
    void solve(int i,vector<int>&nums,vector<vector<int>>&ans){
    if(i>=nums.size()){
        ans.push_back(nums);
        return;
    }
      map<int,bool>m;
      for(int j=i;j<nums.size();j++){
        if(m[nums[j]]==false){
            m[nums[j]]=true;
            swap(nums[i],nums[j]);
            solve(i+1,nums,ans);
            swap(nums[i],nums[j]);
            
        }
        
      
    }}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        solve(0,nums,ans);
        return ans;
    }
};