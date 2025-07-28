class Solution {
public:
   void solve(int i,vector<int>&candidates,vector<int>&temp,vector<vector<int>>&ans,int target){
       if(i>=candidates.size()){
        if(target==0){
            ans.push_back(temp);
        }
        
        return;
       }
       if(target<0){
        return;
       }
       temp.push_back(candidates[i]);
       solve(i,candidates,temp,ans,target-candidates[i]);
       temp.pop_back();
       solve(i+1,candidates,temp,ans,target);

   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int i=0;
        solve(i,candidates,temp,ans,target);
        return ans;
    }
};