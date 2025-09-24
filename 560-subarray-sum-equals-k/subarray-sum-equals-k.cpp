class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        m[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(m[sum-k]>0){
                 ans=ans+m[sum-k];
            }
            m[sum]++;
        }
        return ans;
    }
};