class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        if(nums.size()==0){
            return ans;
        }
        int a=0;
        int b=0;
        string s="";
        for(int i=1;i<nums.size();i++){
            long element=long(nums[i])-long(nums[b]);
            if(element==1){
                b=i;  
            }
            else{
              if(a==b){
                s=to_string(nums[a]);
                ans.push_back(s);
              }
              else{
                s=to_string(nums[a])+"->"+to_string(nums[b]);
                ans.push_back(s);
              }
              a=i;
              b=i;
            }
        }
        cout<<a<<" "<<b<<endl;
        if(a==b){
            ans.push_back(to_string(nums[a]));
        }
        else{
            ans.push_back(to_string(nums[a])+"->"+to_string(nums[b]));
        }

        return ans;
    }
};