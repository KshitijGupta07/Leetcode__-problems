class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int>prefix;
        vector<int>suffix;
        int m=INT_MAX;
        for(int i=0;i<nums.size();i++){
            m=min(m,nums[i]);
            prefix.push_back(m);
        }
        m=INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
            m=min(m,nums[i]);
            suffix.push_back(m);
        }
        reverse(suffix.begin(),suffix.end());
        int ans=INT_MAX;
        for(int i=1;i<nums.size()-1;i++){
            if(prefix[i]<nums[i]&&suffix[i]<nums[i]){
                ans=min(ans,nums[i]+prefix[i]+suffix[i]);
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};