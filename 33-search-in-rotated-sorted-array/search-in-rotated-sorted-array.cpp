class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)>>1;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[0]){
                if(target>=nums[0]&&target<=nums[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }


            }
            else{
                if(target>=nums[mid]&&target<=nums[nums.size()-1]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};