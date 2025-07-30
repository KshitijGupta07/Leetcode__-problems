class Solution {
public:
    void heapify(vector<int>&nums,int i,int n){
        
        int index=i;
        if(2*i+1<n&&nums[2*i+1]>nums[index]){
             index=2*i+1;
        }
        if(2*i+2 <n &&nums[2*i+2]>nums[index]){
            index=2*i+2;
        }
        if(index!=i){
            swap(nums[index],nums[i]);
            heapify(nums,index,n);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=n/2 -1;i>=0;i--){
            heapify(nums,i,n);
        }
        for(int i=n-1;i>n-k;i--){
            swap(nums[0],nums[i]);
            heapify(nums,0,i);
        }
        return nums[0];
    }
};