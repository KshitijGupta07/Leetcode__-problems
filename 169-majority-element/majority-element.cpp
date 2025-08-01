class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=pow(10,9)+1;
        int count=0;
        for(int i=0;i<nums.size();i++){
             if(count==0){
                element=nums[i];
                count=1;
             }
             else if(element==nums[i]){
                count++;
             }
             else{
                count--;
             }
        }
        return element;
    }
};