class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end=nums.size()-1;
        bool r=false;
        if(nums.size()==1){
            return true;
        }
        for(int i=nums.size()-2;i>=0;i--){
            if(i+nums[i]<end||nums[i]==0){
                r=false;
            }
            else{
                  end=i;
                  r=true;
            }
        }
        return r;
    }
};