class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int count=1;
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
                
            }
            else{
                ans.push_back(count);
                count=1;
            }
            
        }

        ans.push_back(count);
        count=0;
        
        for(int i=0;i<ans.size();i++){
            if(ans[i]==1){
                return -1;
            }
            if(ans[i]%3==0){
                count+=ans[i]/3;
            }
            if(ans[i]%3==2){
                count+=ans[i]/3 +1;
            }
            if(ans[i]%3==1&&ans[i]%2==0){
                count+=ans[i]/3+1;
            }
            if(ans[i]%3==1&&ans[i]%2==1){
                count+=ans[i]/3+1;
            }
        }
        
        return count;
    }
};