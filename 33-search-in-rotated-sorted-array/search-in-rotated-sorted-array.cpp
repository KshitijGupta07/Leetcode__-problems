class Solution {
public:
int findpivot(vector<int>&nums){
    int start=0;
    int end=nums.size()-1;
    while(start<end){
        int mid=(start+end)/2 ;
        cout<<mid<<endl;
        if(mid>0&&mid<nums.size()-1&&nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
            return mid;

        }
        else if(mid==0&&nums[0]>nums[1]){
            return 0;
        }
        else if(nums[mid]>=nums[start]){
             start=mid+1;
        }
        
        else if(nums[mid]<nums[start]){
             end=mid-1;
        }
    }
    return start;
}
   int binarysearch(int start,int end,int target,vector<int>&nums){
    if(nums.size()==1){
        if(nums[0]==target){
            return 0;
        }
        else{
            return -1;
        }
    }
       while(start<=end){
           int mid=(start+end)/2;
           if(nums[mid]==target){
            return mid;
           }
           else if(nums[mid]>target){
               end=mid-1;
           }
           else{
               start=mid+1;
           }
       }
       return -1;
   }
    int search(vector<int>& nums, int target) {
        int pivot=findpivot(nums);
        cout<<pivot<<endl;
         int x=binarysearch(0,pivot,target,nums);
         int y=binarysearch(pivot+1,nums.size()-1,target,nums);
         if(x==-1&&y==-1){
            return -1;
         }
         if(x!=-1){
            return x;
         }
         return y;
    }
};