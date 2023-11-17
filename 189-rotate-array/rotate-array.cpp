class Solution {
public:

   
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=ans[(nums.size()-k+i)%nums.size()];
        }
      


    }
};