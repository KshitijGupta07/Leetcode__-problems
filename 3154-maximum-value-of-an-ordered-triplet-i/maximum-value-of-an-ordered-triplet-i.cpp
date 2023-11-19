class Solution {
public:
    long long maximumTripletValue(vector< int >& nums) {
       vector<long long > ans;
       for(int i=0;i<nums.size();i++){
           ans.push_back(nums[i]);
       }
       long long  int max=INT_MIN;
    for(int i=0;i<ans.size()-2;i++){
        for(int j=i+1;j<ans.size()-1;j++){
            for(int k=j+1;k<ans.size();k++){
                long long element=(ans[i]-ans[j])*ans[k];
                if(element>max){
                   max=(ans[i]-ans[j])*ans[k];
                }
            }
        }
    }
    if(max<0){
        return 0;
    }
    return max;
    }
};