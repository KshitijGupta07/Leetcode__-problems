class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> prefix = nums;

        for(int i=1; i<prefix.size(); i++){
            prefix[i] += prefix[i-1];
        }

        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            int start = max(0, i-nums[i]);

            if(start == 0){
                sum += prefix[i];
            }

            else{
                sum += (prefix[i] - prefix[start-1]);
            }

        }

        return sum;

    }
};