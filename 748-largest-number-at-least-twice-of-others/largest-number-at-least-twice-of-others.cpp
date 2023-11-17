class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxindex=0;
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[maxindex]<nums[i]){
                maxindex=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[maxindex]>=2*nums[i]){
                count++;
            }
        }
        if(count==nums.size()-1){
            return maxindex;
        }
        return -1;
    }
};