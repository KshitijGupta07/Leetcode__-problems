class Solution {
public:
   int calci(vector<int>&nums,int k){
              int l=0;
        int r=0;
        int ans=0;
        map<int,int>m;
        while(r<nums.size()){
            m[nums[r]]++;
           
            while(m.size()>k){
                m[nums[l]]-=1;
                if(m[nums[l]]==0){
                    m.erase(nums[l]);
                }
                l++;
            }
            ans+=(r-l+1);
            r++;
            
        }
        

        return ans;
   }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int ans=0;
        map<int,int>m;
        while(r<nums.size()){
            m[nums[r]]++;
           
            while(m.size()>k){
                m[nums[l]]-=1;
                if(m[nums[l]]==0){
                    m.erase(nums[l]);
                }
                l++;
            }
            ans+=(r-l+1);
            r++;
            
        }
        
        return ans-calci(nums,k-1);
    }
};