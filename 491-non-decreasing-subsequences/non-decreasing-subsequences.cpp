class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&temp,int prev,int curr,vector<int>&nums,map<int,bool>&m){
        if(curr>=nums.size()){
            if(temp.size()>1){
            ans.push_back(temp);
            }
            return;
        }
       if(prev==-1||(nums[curr]>=nums[prev]&&m[curr]==false)){

          temp.push_back(nums[curr]);
          
          
          solve(ans,temp,curr,curr+1,nums,m);
        
        temp.pop_back();
          
       } 
        if(prev==-1||nums[curr]!=temp.back()){
       solve(ans,temp,prev,curr+1,nums,m);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        map<int,bool>m;
        solve(ans,temp,-1,0,nums,m);
        return ans;
    }
};