class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
         int start=0;
         int end=nums.size()-1;
         while(start<end){
            int mid=(start+end)/2 ;
            if(mid>0&&mid<nums.size()-1&&nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(mid+1<nums.size()){
                if(nums[mid]<nums[mid+1]){
                start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            else if(mid-1>=0){
                if(nums[mid]>nums[mid-1]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }

         }
        return start;
    }
};