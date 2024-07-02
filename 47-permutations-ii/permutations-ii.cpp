class Solution {
public:
  void solve(vector<int>&nums,vector<vector<int>>&final,int index){
    if(index>=nums.size()){
        final.push_back(nums);
    }
    map<int,int>mpp;
    for(int j=index;j<nums.size();j++){
        
        if(mpp.find(nums[j])!=mpp.end()){
           continue;
        }
        else{
            mpp[nums[j]]++;
               swap(nums[j],nums[index]);
         solve(nums,final,index+1);
      
        //backtrack the elements and bring them to original position
        swap(nums[index],nums[j]);
            
        }
        
    
    }
  }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>>final;
        
        
        solve(nums,final,0);
          return final;
    }
};