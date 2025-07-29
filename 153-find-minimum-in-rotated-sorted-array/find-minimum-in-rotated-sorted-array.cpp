class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[0]<nums[mid]){
                start=mid+1;
            }
            else{
                if(mid>0&&nums[mid]<nums[mid-1]){
                    return nums[mid];
                }
                else{
                    end=mid-1;
                }
            }
        }
        if(start==0){
            return min(nums[start],nums[start+1]);
        }
        if(start==nums.size()||start==nums.size()-1){
            return nums[0];
        }
        return min(nums[start],nums[start-1]);

    }
};