class Solution {

public:
    bool canJump(vector<int>& nums) {
        
    int reach=0;
        if(nums[0]==0&&nums.size()>1){
            return false;
        }
        if(nums.size()==1){
            return true;
    }
        for(int i=0;i<nums.size();i++){
        
            

            if(reach<i){
                return false;
                break;
            }
            reach=max(reach,nums[i]+i);
        }
        
        return true;
    }
};
