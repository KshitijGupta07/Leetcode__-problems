class Solution {
public:
    int countPartitions(vector<int>& nums) {
           vector<int>prefix(nums.size(),0);
           prefix[0]=nums[0];
           for(int i=1;i<prefix.size();i++){
            prefix[i]+=prefix[i-1]+nums[i];
           }
           int count=0;
           cout<<prefix[nums.size()-1]<<endl;
           for(int i=0;i<nums.size()- 1;i++){
               int a=prefix[nums.size()-1]-prefix[i];
               int b=prefix[i];
               cout<<a<<" "<<b<<endl;
               if((a-b)%2==0){
                count++;
               }
           }
           return count;
    }
};