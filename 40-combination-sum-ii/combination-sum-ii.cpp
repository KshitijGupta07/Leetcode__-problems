class Solution {
public:
   void solve(int i,vector<int>&candidates,vector<int>temp,vector<vector<int>>&ans,int target){
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
      solve(i+1,candidates,temp,ans,target-candidates[i]);
      while(i+1<candidates.size()&&candidates[i]==candidates[i+1]){
        i+=1;
      }
      temp.pop_back();
      solve(i+1,candidates,temp,ans,target);

   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int i=0;
        vector<int>temp;
        vector<vector<int>>ans;
        solve(i,candidates,temp,ans,target);
        return ans;
    }
};