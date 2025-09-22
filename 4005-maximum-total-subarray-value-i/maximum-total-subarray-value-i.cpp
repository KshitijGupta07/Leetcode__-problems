class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi1=INT_MIN;
        long long maxi2=INT_MAX;
        for(auto j:nums){
            long long element=j;
            maxi1=max(element,maxi1);
            maxi2=min(element,maxi2);
        }
        long long x=k;
        return (maxi1-maxi2)*x;
    }
};