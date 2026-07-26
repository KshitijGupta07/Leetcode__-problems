class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto j:nums){
            mini=min(j,mini);
            maxi=max(j,maxi);
        }
        return __gcd(mini,maxi);
    }
};