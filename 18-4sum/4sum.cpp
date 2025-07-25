class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4){
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-3;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
        
            for(int j=i+1;j<nums.size()-2;j++){
                  if(j-1>i&&nums[j]==nums[j-1]){
                    continue;
                  }
                 int sum=nums[i]+nums[j];
                 int start=j+1;
                 int end=nums.size()-1;
                 while(start<end){
                     
                     if(start-1>j&&nums[start]==nums[start-1]){
                        start++;
                        continue;
                     }
                     if(end+1<nums.size()-1&&nums[end]==nums[end+1]){
                        end--;
                        continue;
                     }
                     long long element=nums[start]+nums[end];
                     long long x=target;
                     long long y=sum;
                     long long element2=x-y;
                     if(element==element2){
                        ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;
                     }
                     else if(element>element2){
                        end--;
                     }
                     else{
                        start++;
                     }
                     
                 }
            }
        }
        return ans;
    }
};