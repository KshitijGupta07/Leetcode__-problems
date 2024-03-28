class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int element=nums[i];
            while(element>0 && element<=nums.size() && element!=i+1 && nums[element-1]!=element){
                swap(nums[i],nums[element-1]);
                element=nums[i];
            }
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            
                
                if(nums[i]==i+1){
                    continue;
                }
                else{
                    return i+1;
                }
            
        
        }
        return nums.size()+1;
    }
};