class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k){
                ans++;
            }
        }
        int count=ans;
        for(int i=1;i<=50;i++){
            if(i==k)continue;
            int curr=0;
            int maxi=0;
            for(auto j:nums){
                 if(j==i){
                    curr++;
                 }
                 else if(j==k){
                    curr--;
                 }
                 if(curr<0)curr=0;
                 maxi=max(maxi,curr);
            }
            ans=max(ans,count+maxi);
        }
        return ans;
    }
};