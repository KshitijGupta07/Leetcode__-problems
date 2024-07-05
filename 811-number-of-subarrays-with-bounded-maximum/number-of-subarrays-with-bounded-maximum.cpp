class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        long long  sum=0;
        long long  count=0;
        for(int i=0;i<nums.size();i++){
              if(nums[i]<=right){
                count++;
              }
              else{
                
                sum=sum+(count*count+count)/2;
                count=0;
              }
        }
        long long  count2=0;
        long long  sum2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<left){
                count2++;
            }
            else{
                sum2+=(count2*(count2+1))/2;
                count2=0;
            }
        }
        
        return int(sum+(count*(count+1))/2-(sum2+(count2*(count2+1))/2));
    }
};