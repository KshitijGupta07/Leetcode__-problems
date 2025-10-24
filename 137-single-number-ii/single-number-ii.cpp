class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>bit(32,0);
        for(int i=0;i<nums.size();i++){
            for(int j=31;j>=0;j--){
            
                int b=((nums[i])>>j)&1;
                if(b==1){
                    bit[j]++;
                }
            
                
            }
        
        }
         long long  num=0;
         for(auto j:bit){
            cout<<j<<" ";
         }
         for(int i=0;i<32;i++){
            if(bit[i]%3!=0){
                
            num=num|(bit[i]%3)<<i;
            }
         }
         return num;
    }
};