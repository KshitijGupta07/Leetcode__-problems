class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>count;
        vector<int>ans;
        int a=1;
        count.push_back(a);
        for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]+1){
            a++;
            count.push_back(a);
        }
        else{
            a=1;
            count.push_back(a);
        }
        }
        for(int i=0;i<=nums.size()-k;i++){
            if(count[i+k-1]-count[i]+1==k){
                ans.push_back(nums[i+k-1]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};