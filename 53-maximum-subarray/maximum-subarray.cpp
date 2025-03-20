class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
                maxi=max(maxi,nums[i]);
        }
        if(maxi<=0){
            return maxi;
        }
        int maxsum=INT_MIN;
        int ans=0;
        for(int i=0;i<nums.size();i++){
              ans+=nums[i];
              cout<<ans<<" "<<maxsum<<endl;
              if(ans<0){
                maxsum=max(maxsum,ans);
                ans=0;
              }
              maxsum=max(maxsum,ans);
        }
        maxsum=max(maxsum,ans);
        return maxsum;
    }
};