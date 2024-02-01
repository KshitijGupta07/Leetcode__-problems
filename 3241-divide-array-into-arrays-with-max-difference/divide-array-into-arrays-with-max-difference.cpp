class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        
        
        for(int i=0;i<nums.size()-2;i+=3){
            vector<int>final;
            if(nums[i+2]-nums[i]<=k){
                 final.push_back(nums[i]);
                 final.push_back(nums[i+1]);
                 final.push_back(nums[i+2]);
                 ans.push_back(final);
                 
                 
            }
            else{
                return {};
            }
            
        }
        
            return ans;
        
        
    }
};