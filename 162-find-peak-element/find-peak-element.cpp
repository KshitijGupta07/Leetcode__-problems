class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            int mid=(start+end)/2 ;
            if(mid>0&&mid<nums.size()-1&&nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(mid+1<nums.size()&&nums[mid]<nums[mid+1]){
                start=mid+1;
            }
            else if(mid-1>=0&&nums[mid-1]>nums[mid]){
                end=mid-1;
            }
            else if(mid==0){
                if(nums[0]>nums[1]){
                    return 0;
                }
                else{
                    start=mid+1;
                }
            }
            else if(mid==nums.size()-1){
                if(nums[mid]>nums[mid-1]){
                    return mid;
                }
                else{
                    end=mid-1;
                }
            }
        
            
        }
        return start;
    }
};