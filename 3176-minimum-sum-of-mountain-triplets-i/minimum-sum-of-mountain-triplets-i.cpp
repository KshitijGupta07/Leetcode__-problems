class Solution {
public:
int  check(vector<int>& nums){
    int min=INT_MAX;
    for(int i=0;i<nums.size()-2;i++){
        for(int j=i+1;j<nums.size()-1;j++){
            for(int k=j+1;k<nums.size();k++){
                if(nums[i]<nums[j]&&nums[k]<nums[j]){
                   if(min>nums[i]+nums[j]+nums[k]){
                         min=nums[i]+nums[j]+nums[k];
                   }
                }
            }
        }
    }
    return min;
}
    int minimumSum(vector<int>& nums) {
        if(check(nums)==INT_MAX){
            return -1;
        }
        return check(nums);

    }
};