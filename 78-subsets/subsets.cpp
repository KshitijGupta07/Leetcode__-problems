class Solution {
public:
void solve(vector<vector<int>>& ans,vector<int> output,int index,vector<int>& nums){
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }
      
       solve(ans,output,index+1,nums);
        
        int element=nums[index];
       output.push_back(element);
       solve(ans,output,index+1,nums);
       

    
}
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>ans;
         vector<int>output;
         
         
         solve(ans,output,0,nums);
         return ans;
    }
};