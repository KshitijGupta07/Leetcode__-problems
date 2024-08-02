class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int s=0;
            for(int j=0;j<nums.size();j++){
                if((nums[j]>>i&1)==1){
                    s++;
                }
            }
            s=s%3;
            if(s!=0){
                ans=ans|s<<i;
            }
        }
        return ans;
    }
};