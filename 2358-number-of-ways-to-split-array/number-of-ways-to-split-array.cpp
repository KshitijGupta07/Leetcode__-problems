class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0;
        for(auto j:nums){
            sum+=j;
        }
        int count=0;
        long long  sum2=0;
        for(int i=0;i<nums.size()-1;i++){
            sum2+=nums[i];
            if(sum2>=sum-sum2){
                count++;
            }
        }
        return count;
    }
};