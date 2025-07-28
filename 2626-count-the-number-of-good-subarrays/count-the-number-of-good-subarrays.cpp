class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        int l=0;
        int r=0;
        int pair=0;
        long long count=0;
        map<int,int>m;
        while(r<nums.size()){
           
           pair+=m[nums[r]];
           m[nums[r]]+=1;
           
        
            while(pair>=k){
                count+=nums.size()-r;
                m[nums[l]]-=1;
                pair-=(m[nums[l]]);
                
                l++;
            }
        
           
           r++;
        }
         
        return count;
    }
};