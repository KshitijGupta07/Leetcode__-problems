class Solution {
public:
     void solve(vector<vector<int>>&ans,int i,vector<int>temp,vector<int>&nums){
        if(i>=nums.size()){
    
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(ans,i+1,temp,nums);
        while(i<nums.size()-1&&nums[i]==nums[i+1]){
            i++;
        }
        
        temp.pop_back();
        solve(ans,i+1,temp,nums);
        
     }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>temp;
        solve(ans,0,temp,nums);
        return ans;
    }
};