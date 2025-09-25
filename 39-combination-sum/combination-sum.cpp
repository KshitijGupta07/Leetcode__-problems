class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>temp,vector<int>&candidates,int i,int target){
        if(target<0){
            return;
        }
        if(i>=candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return ;
        }
        temp.push_back(candidates[i]);
        solve(ans,temp,candidates,i,target-candidates[i]);
        temp.pop_back();
        solve(ans,temp,candidates,i+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int i=0;
        solve(ans,temp,candidates,i,target);
        return ans;
    }
};