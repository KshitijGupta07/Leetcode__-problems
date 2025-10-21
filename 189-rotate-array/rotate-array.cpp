class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        if(k==0){
            return;
        }
        reverse(nums.begin(),nums.end());

        int start=0;
        int end=k-1;
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
        start=k;
        end=nums.size()-1;
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
};