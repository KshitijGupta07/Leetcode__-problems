class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int element1=0;
        int element2=0;
        int count1=0;
        int count2=0;
        if(nums.size()==2){
            if(nums[0]==nums[1]){
                return {nums[0]};
            }
            else{
                return nums;
            }
        }
        if(nums.size()==1){
            return nums;
        }
        for(int i=0;i<nums.size();i++){
            if(count1==0&&nums[i]!=element2){
                element1=nums[i];
                count1=1;
            }
           else if(count2==0&&nums[i]!=element1){
                element2=nums[i];
                count2=1;
            }
            else if(nums[i]==element1){
                count1++;
            }
            else if(nums[i]==element2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
      for(int i=0;i<nums.size();i++){
            if(nums[i]==element1){
                count1++;
            }
            else if(nums[i]==element2){
                count2++;
            }
      }
      vector<int>ans;
      if(count1>nums.size()/3){
         ans.push_back(element1);
      }
      if(count2>nums.size()/3&&element1!=element2){
        ans.push_back(element2);
      }
    
      
        return ans;
    }
};