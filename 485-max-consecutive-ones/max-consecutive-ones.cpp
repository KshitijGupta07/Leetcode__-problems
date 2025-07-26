class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size()==1){
            if(nums[0]==1){
                return 1;
            }
            else{
                return 0;
            }
        }
        int count=0;
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]&&nums[i]==1){
                if(count==0){
                    count=2;
                }
                else{
                    count+=1;
                }
            }
          
           
            else{
               ans=max(ans,count);
               count=0;
            }
        }
        if(count==0){
            if(nums.back()==1){
                count++;
            }
            
        }
        if(count==0){
            if(nums[0]==1){
                count++;
            }
        }
        return max(ans,count);
    }
};