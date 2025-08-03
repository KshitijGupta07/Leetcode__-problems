class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>positive;
        vector<int>negative;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                positive.push_back(nums[i]);
            }
            else{
                negative.push_back(nums[i]);
            }
        }
        int i=0;
        int j=0;
        int idx=0;
        while(i<positive.size()&&j<negative.size()){
             if(idx%2==0){
                nums[idx]=positive[i];
                i++;
             }
             else{
                nums[idx]=negative[j];
                j++;
             }
             idx++;
        }
        nums[idx]=negative[j];
        return nums;
    }
};