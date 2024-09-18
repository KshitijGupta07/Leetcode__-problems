class Solution {
public:
  int compare(int a,int b){
    string x=to_string(a)+to_string(b);
    string y=to_string(b)+to_string(a);
    for(int i=0;i<x.length();i++){
        if(x[i]>y[i]){
            return a;
        }
        else if(x[i]<y[i]){
            return b;
        }
    }
    return -1;
  }
    string largestNumber(vector<int>& nums) {
        string ans="";
        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<nums.size()-i;j++){
                  if(compare(nums[j],nums[j+1])==nums[j+1]){
                      swap(nums[j],nums[j+1]);
                  }
                }
            }
        
        for(auto j:nums){
            ans+=to_string(j);
        }
        if(ans.length()>1){
            while(ans[0]=='0'){
                if(ans.length()==1){
                    if(ans[0]=='0'){
                        return ans;
                    }
                }
                ans.erase(ans.begin());
            }
        }
        return ans;
    }
};