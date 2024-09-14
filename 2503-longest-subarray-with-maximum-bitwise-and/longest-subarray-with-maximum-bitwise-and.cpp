class Solution {
public:
bool check(int k,int a){
    while(a!=0&&k!=0){
        if((k&1)==1&&(a&1)!=1){
            return false;
        }
        k=k>>1;
        a=a>>1;
    }
    while(k!=0){
         if((k&1)==1){
            return false;
         }
    }
    return true;
}
    int longestSubarray(vector<int>& nums) {
        int k=INT_MIN;
        for(auto j:nums){
            k=max(k,j);
        }
        
        int l=0;
        int r=0;
        int maxlen=0;
        while(r<nums.size()){
        
            if(check(k,nums[r])==true){
               r++;
                
            }
            else{
               if(l==r){
                l++;
                r++;
                maxlen=max(maxlen,r-l+1);
               } 
               else{
                 l++;
                 maxlen=max(maxlen,r-l+1);
               }
                
            }
             
        }
        r=nums.size()-1;
        if(maxlen==0){
            return nums.size();
        }
        cout<<r<<" "<<l<<endl;
        cout<<r-l+1<<endl;
        return max(r-l+1,maxlen);
        

    }
};