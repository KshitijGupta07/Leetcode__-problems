class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxi=INT_MIN;
        vector<long long >prefix;
        vector<long long >suffix;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
           prefix.push_back(maxi);
        }
        maxi=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
          maxi=max(maxi,nums[i]);
          suffix.push_back(maxi);
        }
        reverse(suffix.begin(),suffix.end());
        long long ans=0;
        for(int j=1;j<nums.size()-1;j++){
            long long element=(prefix[j-1]-nums[j])*suffix[j+1];
            ans=max(ans,element);
        }
        return ans;
    }

};