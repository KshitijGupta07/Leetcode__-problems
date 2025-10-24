class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int m=(s+e)>>1;
            if(nums[m]==target){
                return m;
            }
            else if(nums[m]>target){
                e--;
            }
            else{
                s++;
            }
        }
        return -1;
    }
};