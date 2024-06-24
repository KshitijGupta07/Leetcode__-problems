class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        
        
        for(int i=0;i<nums.size();i++){
            if(count%2==1){
                nums[i]=nums[i]^1;
            }
          if(nums[i]==0){
            count++;
          }
          }
        
         
        
        
     
        
        return count;
    }
};