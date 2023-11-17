class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size()-1;i++){
            ans.push_back(nums[i+1]-nums[i]);
        }
        int count1=0;
        int count2=0;
        
        for(int i=0;i<ans.size();i++){
            if(ans[i]>0){
                count1++;
            }
            if(ans[i]<0){
                count2++;
            }
            
        }
        if(count1==0||count2==0){
            return true;
        }
        return false;
    }
};