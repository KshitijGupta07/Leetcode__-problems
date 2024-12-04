class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        map<int,int>m;
        map<int,bool>present;
        map<int,int>found;
        int sum=0;
        for(auto j:nums){
            sum+=j;
        }
        for(int i=0;i<nums.size();i++){
            m[i]=sum-nums[i];
            present[nums[i]]=true;
            found[nums[i]]++;
        }
        int ans=INT_MIN;
        for(auto j:m){
            if(j.second%2==0&&present[j.second/2]){
                
                if(nums[j.first]!=j.second/2){
                    ans=max(ans,nums[j.first]);
                }
                else if(nums[j.first]==j.second/2&&found[j.second/2]>1){
                    ans=max(ans,nums[j.first]);
                }
            }
        }
        return ans;

    }
};