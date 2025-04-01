class Solution {
public:
    int pivot(vector<int>&nums){
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2 ;
            if(mid<nums.size()-1&&nums[mid]<nums[mid+1]){
                if(nums[mid]>nums[0]){
                    start=mid+1;
                }
                else if(mid>0&&nums[mid]<nums[mid-1]){
                     return mid-1;
                }
                else{
                    end=mid-1;
                }
            }
            else{
                return mid;
            }

        }
        
        return start;
    }
     int binarysearch(vector<int>&nums,int start,int end,int target){
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                start=mid +1;
            }
        }
        return -1;
     }
    int search(vector<int>& nums, int target) {
        int p= pivot(nums);
        int start=-1;
        int end=-1;
        cout<<p<<endl;
        if(target>=nums[0]&&target<=nums[p]){
              start=0;
              end=p;
        }
        else{
            start=p+1;
            end=nums.size()-1;
        }
        int ans=binarysearch(nums,start,end,target);
        return ans;
    }
};