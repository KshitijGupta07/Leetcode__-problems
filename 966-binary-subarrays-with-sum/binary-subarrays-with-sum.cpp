class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
          vector<int>prefix;
          int sum=0;
          for(int i=0;i<nums.size();i++){
              if(nums[i]==1){
                sum+=1;
              }
              prefix.push_back(sum);
          }
          map<int,int>m;
          m[0]=1;
          sum=0;
          for(int i=0;i<prefix.size();i++){
               sum=sum+m[prefix[i]-goal];
               m[prefix[i]]+=1;
          }
          return sum;
          
    }
};