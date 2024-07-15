class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        if(nums.size()==1){
            return nums[0];
        }
        int a=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]>nums[0]){
                if(mid+1<nums.size()&&nums[mid]>nums[mid+1]){
                    a=mid;
                    break;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(mid-1>=0&&nums[mid]<nums[mid-1]){
                    a=mid;
                    break;
                }
                else{
                    end=mid-1;
                }
            }
        }
        cout<<a<<endl;
        if(a==0){
            return min(nums[0],nums[1]);
        }
        if(a==nums.size()-1){
            return min(nums[a],nums[0]);
        }
        return min(nums[a],min(nums[a-1],nums[a+1]));
    }
             
     
};