class Solution {
public:
    void heapify(vector<int>&nums,int i,int n){
        int large=i;
        int left=2*i +1;
        int right=2*i +2;
        if(left<n&&nums[left]>nums[large]){
            large=left;
        }
        if(right<n&&nums[right]>nums[large]){
            large=right;
        }
        if(large!=i){
              swap(nums[large],nums[i]);
              heapify(nums,large,n);
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