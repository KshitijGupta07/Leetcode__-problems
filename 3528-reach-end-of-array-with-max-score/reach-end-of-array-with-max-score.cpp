class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans=0;
        long long element=nums[0];
        int index=0;
        for(int i=1;i<nums.size();i++){
             if(nums[i]>element){
                ans+=(i-index)*element;
                element=nums[i];
                index=i;
             }
        }
        if(index!=nums.size()-1){
            ans+=(nums.size()-1-index)*nums[index];
        }
        
        return ans;
    }
};