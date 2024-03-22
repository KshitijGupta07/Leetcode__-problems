class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int product=1;
        ans.push_back(1);
        for(int i=1;i<nums.size();i++){
           
            product*=nums[i-1];
             ans.push_back(product);
        }
        
        product=1;
        for(int i=nums.size()-1;i>=0;i--){
           ans[i]*=product;
           product*=nums[i];

        }
        return ans;
    }
};