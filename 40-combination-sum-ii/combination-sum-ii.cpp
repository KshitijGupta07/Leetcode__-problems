class Solution {
public:
   void solve(vector<int>&candidates,vector<vector<int>>&ans,vector<int>&output,int target,int index){
    if(target==0){
        ans.push_back(output);
        return;
    }

    for(int i=index;i<candidates.size();i++){
        if(candidates[i]>target){
            break;

        }
        if(i>index&&candidates[i]==candidates[i-1]){
            continue;
        }
        output.push_back(candidates[i]);
        solve(candidates,ans,output,target-candidates[i],i+1);
        output.pop_back();
    }
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>output;
        int index=0;
        
        solve(candidates,ans,output,target,index);
        return ans;
    }
};