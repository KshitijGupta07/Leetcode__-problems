class Solution {
public:
    void solve(vector<vector<int>>&ans,int i,vector<int>temp,vector<int>&candidates,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
         if(i>=candidates.size()){
            return;
        }
        if(target<0){
            return;
        }
        temp.push_back(candidates[i]);
         solve(ans,i,temp,candidates,target-candidates[i]);
         temp.pop_back();
         solve(ans,i+1,temp,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,0,temp,candidates,target);
        return ans;
    }
};