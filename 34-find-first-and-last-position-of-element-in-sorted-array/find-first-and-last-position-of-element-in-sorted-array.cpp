class Solution {
public:
int lastoccurence(vector<int>&nums,int target){
    int start=0;
    int end=nums.size()-1;
     if(binary_search(nums.begin(),nums.end(),target)==true){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]>target){
            end=mid-1;
        }
        else if(nums[mid]<target){
            start=mid+1;
        }
        else{
            if(mid==nums.size()-1||nums[mid]!=nums[mid+1]){
                return mid;
            }
            else{
                start=mid+1;
            }
        }
        
    }
    return start;
}
    return -1;
}
int firstoccurence(vector<int>&nums,int target){
    int start=0;
    int end=nums.size()-1;
    if(binary_search(nums.begin(),nums.end(),target)==true){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]>target){
            end=mid-1;
        }
        else if(nums[mid]<target){
            start=mid+1;
        }
        else{
            if(mid==0||nums[mid]!=nums[mid-1]){
                return mid;
            }
            else{
                end=mid-1;
            }
        }
    }
    return start;
}
    return -1;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int a=lastoccurence(nums,target);
        int b=firstoccurence(nums,target);

        ans.push_back(b);
        ans.push_back(a);
        return ans;
    }
};