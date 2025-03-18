class Solution {
public:
  int count(int a){
    int counter=0;
    while(a>0){
        a=a>>1;
        counter++;
    }
    return counter;
  }
    int longestNiceSubarray(vector<int>& nums) {
        int l=0;
        int used=0;
        int ans=0;
         for(int i=0;i<nums.size();i++){
             
               while((nums[i]&used)>0){
                used=(used^nums[l]);
                l+=1;
               }
               used=(used|nums[i]);
               ans=max(ans,i-l +1);
              
         }
         return ans;

    }
};