class Solution {
public:
    int specialTriplets(vector<int>& nums) {
         map<int,int>l;
         map<int,int>r;
         for(auto j:nums){
            r[j]++;
         }
         int ans=0;
         int element=pow(10,9)+7;
         for(int i=0;i<nums.size();i++){
            r[nums[i]]-=1;
            long long  left=l[2*nums[i]];
        long long  right=r[2*nums[i]];
            ans=(ans%element+(left*right)%element)%element;
            l[nums[i]]+=1;
         }
         return ans;
    }
};