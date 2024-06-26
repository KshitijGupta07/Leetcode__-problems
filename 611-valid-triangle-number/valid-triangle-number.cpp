class Solution {
public:
int binarysearch(vector<int>&nums,int target,int start,int end){
    int ans=0;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]==target){
            ans=mid;
            break;
        }
        else if(nums[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    
    return start;
    
}
    int triangleNumber(vector<int>& nums) {
        int count=0;
        if(nums.size()<3){
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int i=2;i<nums.size();i++){
            int start=0;
            int end=i-1;
            while(start<end){
                if(nums[start]+nums[end]>nums[i]){
                    count+=end-start;
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return max(0,count);
    }
};