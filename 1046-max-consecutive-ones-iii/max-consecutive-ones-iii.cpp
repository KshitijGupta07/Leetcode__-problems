class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int ans=0;
        vector<int>count(2,0);
        while(r<nums.size()){
            count[nums[r]]++;
            while(count[0]>k){
                count[nums[l]]-=1;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};