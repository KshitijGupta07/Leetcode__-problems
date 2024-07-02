class Solution {
public:
//    void solve(vector<vector<int>>&final,vector<int>&nums,vector<int>&temp){
//       if(temp.size()==nums.size()){
//         final.push_back(temp);
//         return;
//       }
//       for(int i=0;i<nums.size();i++){
        
//         map<int,bool>m;
//         if(temp.size()>0){
//             for(int i=0;i<temp.size();i++){
//                 m[temp[i]]=true;
//             }
//         }
//         if(m[nums[i]]==false){
//      temp.push_back(nums[i]);
//             solve(final,nums,temp);
//         temp.pop_back();
//         }
        
//       }
//    }
  void solve(vector<int>&nums,vector<vector<int>>&final,int index){
    if(index>=nums.size()){
        final.push_back(nums);
    }
    for(int j=index;j<nums.size();j++){
        swap(nums[j],nums[index]);
        solve(nums,final,index+1);
        //backtrack the elements and bring them to original position
        swap(nums[index],nums[j]);
    }
  }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>final;
        vector<int>temp;
        
        solve(nums,final,0);
          return final;
    }
};