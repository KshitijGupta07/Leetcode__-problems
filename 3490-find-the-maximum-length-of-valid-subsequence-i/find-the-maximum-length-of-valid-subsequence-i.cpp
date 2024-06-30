class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int,int>m;
         int count1=0;
        int count0=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]%2;
            if(nums[i]%2==0){
                 count0++;
            }
            else{
                count1++;
            }
        }
        
        int len=1;
       
        for(int i=0;i<nums.size()-1;i++){
          if(nums[i]==nums[i+1]){
            continue;
          }
          else{
            len++;
          }
        }
        
        return max(len,max(count1,count0));
    }
};