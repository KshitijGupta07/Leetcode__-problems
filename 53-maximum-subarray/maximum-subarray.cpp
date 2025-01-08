class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int mini=INT_MAX;
        bool s=false;
    
        for(auto j:nums){
            if(j>0){
                s=true;
                break;
            }
            else{
                mini=min(mini,abs(j));
            }
        }
        int sum=0;
        int m=0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            m=max(m,sum);
            if(sum<0){
                
        
                sum=0;
            }
        }
        if(s==true){
            return m;
        }
        return -mini;
    }
};