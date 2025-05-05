class Solution {
public:
  void solve(vector<vector<int>>&ans,vector<int>temp,int index,int target,vector<int>&candidates){
     if(target==0){
       ans.push_back(temp);
       return;
    }
    if(index>=candidates.size()||target<0){
        return;
    }
   
   
    temp.push_back(candidates[index]);
     
     solve(ans,temp,index+1,target-candidates[index],candidates);
     while(index+1<candidates.size()&&candidates[index]==candidates[index+1]){
        index++;
     }
     temp.pop_back();
     solve(ans,temp,index+1,target,candidates);
  }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,0,target,candidates);
        return ans;
    }
};