class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            int start=i+1;
            int end=nums.size()-1;
            int element=nums[i];
            while(start<end){
                if(nums[start]+nums[end]+element==target){
                    return target;
                }
                else if(nums[start]+nums[end]+element>target) {
                    ans.push_back(nums[start]+nums[end]+element);
                    end--;
                }
                else{
                    ans.push_back(nums[start]+nums[end]+element);
                    start++;
                }
            }

        }
         for(int i=0;i<ans.size();i++){
             if(target-1==ans[i]){
                 return target-1;
         }
         if(target+1==ans[i]){
             return target+1;
         }
         }

        int min=ans[0];
        int max=ans[0];
        
       
        
        for(int i=0;i<ans.size();i++){
            if(ans[i]>max){
                max=ans[i];
            }
            
        }
        for(int i=0;i<ans.size();i++){
            if(min>=ans[i]){
                min=ans[i];
            }
            
        }
        
        if(abs(target-min)>abs(target-max)){
            return max;
        }
    
        return min;
        
    }
};