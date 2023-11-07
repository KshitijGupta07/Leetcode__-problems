class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        for(int i=0;i<nums.size();){
            if(nums[i]==val){
                nums.erase(nums.begin()+i);
            }
            else{
                i++;
            }
        }
        for(int i=0;i<nums.size();i++){
            count++;
        }
        return count;
    }
};