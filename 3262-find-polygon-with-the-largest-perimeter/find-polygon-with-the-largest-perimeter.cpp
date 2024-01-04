class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
         sort(nums.begin(),nums.end());
       long long  int ans=0;
        for( int i=0;i<nums.size();i++){
            ans=ans+nums[i];
            
}
        
        for( int i=nums.size()-1;i>=0;i--){
                        ans=ans-nums[i];

              if(ans>nums[i]){
                  
                  return ans+nums[i];
                  break;
              }
        
        }
        return -1;
    }
};