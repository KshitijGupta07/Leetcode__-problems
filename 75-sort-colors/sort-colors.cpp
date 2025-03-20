class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int m=0;
        while(m<=end){
            if(nums[m]==0){
                swap(nums[m],nums[start]);
                start++;
                m++;
            }
            else if(nums[m]==2){
                swap(nums[m],nums[end]);
                end--;
                
            }
            else{
                m++;
            }
        }
        return;
    }
};