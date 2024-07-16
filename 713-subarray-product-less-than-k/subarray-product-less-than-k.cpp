class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p=1;
        int l=0;
        int r=0;
        int count=0;
        if(k==0){
            return count;
        }
        while(r<nums.size()){
            
                p=p*nums[r];
              
                
            
               
                
                while(p>=k&&p>0){
                    p/=nums[l];
                    l=l+1;
                }
               if(p==0){
                break;
               }
              count=count+r-l+1;
              cout<<count<<endl;
           r++; 
        }
        if(count<=0){
            return 0;
        }
        
        return count;
    }
};