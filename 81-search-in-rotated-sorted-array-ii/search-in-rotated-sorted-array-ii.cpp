class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int end=nums.size()-1;
        while(low<=end){
            int mid=(low+end)/2 ;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]==nums[low]&&nums[mid]==nums[end]){
                low++;
                end--;
            }
            else {
                if(nums[mid]>=nums[low]){
                    if(target>=nums[low]&&target<=nums[mid]){
                        end=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
                else{
                    if(target>=nums[mid]&&target<=nums[end]){
                        low=mid+1;
                    }
                    else{
                        end=mid-1;
                    }
                }
            }
        }
        return false;
    }
};