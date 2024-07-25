class Solution {
public:
    void heapify(int i,vector<int>&nums,int n){
        int index=i;
        
            int leftindex=2*i+1;
            int rightindex=2*i+2;
            if(leftindex<n&&nums[index]<nums[leftindex]){
                index=leftindex;
            }
            if(rightindex<n&&nums[index]<nums[rightindex]){
                  index=rightindex;
            }
        
        if(index!=i){
            swap(nums[index],nums[i]);
            heapify(index,nums,n);
        }
    }
    vector<int> sortArray(vector<int>& nums) {

       for(int i=nums.size()/2 -1;i>=0;i--){
          heapify(i,nums,nums.size());
       }
       
       for(int i=nums.size()-1;i>0;i--){
           swap(nums[i],nums[0]);
           heapify(0,nums,i);
       }
       return nums;
    }
};