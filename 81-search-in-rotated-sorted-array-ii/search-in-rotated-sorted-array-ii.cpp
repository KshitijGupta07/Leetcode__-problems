class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            
            while(start+1<nums.size()&&nums[start]==nums[start+1]){
                start++;
            }
            while(end-1>=0&&nums[end]==nums[end-1]){
                end--;
            }
            int mid=(start+end)>>1;
            if(nums[mid]==target){
                return true;
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
        return false;
    }
};