class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int count1=0;
        int count2=0;
        int ans1=0;

        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=left&&nums[i]<=right){
                count1++;
                ans1+=count1;
                count2=0;
            }
            else{
                if(nums[i]<left){
                    count1++;
                    ans1+=count1;
                    count2++;
                    ans1-=count2;
                    
                }
                else{
                   count1=0;
                
                   count2=0;
                   
                }
            }
        }
        
        return ans1;
    }
};