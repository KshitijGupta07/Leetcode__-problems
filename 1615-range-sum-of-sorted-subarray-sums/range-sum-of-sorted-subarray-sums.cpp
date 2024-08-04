class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long >ans;
         long long  element=pow(10,9)+7;
        for(int i=0;i<nums.size();i++){
            long long  count=0;
            for(int j=i;j<nums.size();j++){
                  count+=nums[j]%element;
                  ans.push_back(count);
            }
        }
        sort(ans.begin(),ans.end());
        long long  total=0;
       
        for(int i=left-1;i<right;i++){
           total+=ans[i]%element;

        }
        return total%element;
    }
};