class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int a=-1;
        int b=-1;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                 if(nums[i]<nums[j]){
                    a=i;
                    b=j;
                 }
            }
        }
        if(a==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        swap(nums[a],nums[b]);
        for(int i=a+1;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++ ){
                if(nums[i]>nums[j]){
                    swap(nums[i],nums[j]);
                }
            }
        }
    }
};