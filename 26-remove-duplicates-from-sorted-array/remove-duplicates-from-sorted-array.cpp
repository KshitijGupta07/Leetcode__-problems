class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int i=0;
       int j=0; 
       while(j+1<nums.size()){
        if(nums[j]==nums[j+1]){
            nums[i]=nums[j];
            j++;
        }
        else{
            nums[i]=nums[j];
            i++;
            j++;
        }
       }
       nums[i]=nums[j];
       return i+1;
    }
};