class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int count=0;
        
        
        sort(nums.begin(),nums.end());
        
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            if(nums[start]+nums[end]==limit){
                count++;
                start++;
                end--;
            }
            else if(nums[start]+nums[end]>limit){
                count++;
                end--;
            }
            else{
                start++;
                end--;
                count++;
            }
        }
        return count;
    }
};