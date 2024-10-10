class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>maxi(nums.size());
        maxi[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            maxi[i]=max(maxi[i+1],nums[i]);
        }
        int left=0;
        int right=0;
        int ans=0;
        while(right<n){
            while(left<right&&nums[left]>maxi[right]){
                left++;
            }
           ans=max(ans,right-left);
             right++;
        }
        return ans;
    }
};