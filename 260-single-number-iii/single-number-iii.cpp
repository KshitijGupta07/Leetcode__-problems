class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        int mask=1;
        while(1){
            if((mask&ans)==0){
               mask= mask<<1;
            }
            else break;
        }
        int a=0;
        int b=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&mask){
                a=a^nums[i];
            }
            else{
                b=b^nums[i];
            }
        }
        return {a,b};
    }
};