class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        m[0]=1;
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            count+=m[sum-k];
            cout<<sum<<" "<<k-sum<<endl;
            m[sum]++;
        }
        return count;
    }
};