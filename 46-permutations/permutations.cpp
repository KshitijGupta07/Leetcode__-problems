class Solution {
public:
    void solve(vector<int>&nums,int j,vector<vector<int>>&ans){
        if(j>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=j;i<nums.size();i++){
            swap(nums[i],nums[j]);
            solve(nums,j+1,ans);
            swap(nums[i],nums[j]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,0,ans);
        return ans;
    }
};