class Solution {
public:

    int minSubarray(vector<int>& nums, int p) {
        int  sum=0;
        for(int i=0;i<nums.size();i++){
            sum=(sum+nums[i])%p;
        }
        int  a=sum%p;
        
        if(a==0){
            return 0;
        }
        int c=0;
        unordered_map<int,int>m;
        int l=nums.size();
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
              c=(c+nums[i])%p;
             int n=(c-a+p)%p;
           if( m.find(n)!=m.end()){
                l=min(l,i-m[n]);
           }
           m[c]=i;
        }
        cout<<l<<endl;
        if(l==nums.size()){
            return -1;
        }
        return l;
        
        
      
    }
};