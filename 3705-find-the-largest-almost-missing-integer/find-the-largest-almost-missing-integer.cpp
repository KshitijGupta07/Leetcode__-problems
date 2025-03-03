class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto j:nums){
            m[j]++;
        }
        if(k==1){
            sort(nums.begin(),nums.end());
            for(int i=nums.size()-1;i>=0;i--){
                if(m[nums[i]]==1){
                    return nums[i];
                }
            }
            
        }
        if(k==nums.size()){
            int mi=INT_MIN;
            for(auto j:m){
                mi=max(j.first,mi);
            }
            return mi;
        }
        if(m[nums[0]]>1&&m[nums.back()]>1){
            return -1;
        }
        else if(m[nums.back()]>1){
            return nums[0];
        }
        else if(m[nums[0]]>1){
            return nums.back();
        }
        return max(nums.back(),nums[0]);
    }
};