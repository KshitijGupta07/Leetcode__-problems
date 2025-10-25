class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2 ;
            if(mid==0&&nums[mid]>nums[mid+1]){
                return 0;
            }
            else if(mid==nums.size()-1&&nums[mid]>nums[mid-1]){
                return mid;
            }
             else if(mid==0&&nums[mid]<nums[mid+1]){
                start=mid+1;
            }
            else if(mid==nums.size()-1&&nums[mid]<nums[mid-1]){
                end=mid-1;
            }
            else if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]){
                return mid;
            }
           
            else if(nums[mid]>nums[mid+1]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};