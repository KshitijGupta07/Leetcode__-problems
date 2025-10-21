class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            product=product*nums[i];
            ans=max(ans,product);
            if(product==0){
                product=1;
            }
        }
        reverse(nums.begin(),nums.end());
        product=1;
        
        for(int i=0;i<nums.size();i++){
            product=product*nums[i];
            ans=max(ans,product);
            if(product==0){
                product=1;
            }
        }
        return ans;
    }
};