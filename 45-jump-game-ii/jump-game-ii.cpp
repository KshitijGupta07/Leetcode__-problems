class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int farther=0;
        int jump=0;

        int current=0;
        for(int i=0;i<nums.size()-1;i++){
            farther=max(farther,nums[i]+i);
            if(i==current){
                jump++;
                current=farther;
            }
        }
        return jump;
    }
};