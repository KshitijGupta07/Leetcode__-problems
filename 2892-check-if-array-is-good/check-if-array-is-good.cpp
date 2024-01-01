class Solution {
public:
    bool isGood(vector<int>& nums) {
        int max=nums[0];
        int count=0;
        int n=nums.size()-1;
        for(int i=1;i<nums.size();i++){
            if(max<nums[i]){
                max=nums[i];
            }
        }
        int a=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==max){
               count++;
           }
           a+=nums[i];
        }
        
        int sum=(n*n+3*n)/2;
        cout<<a<<" "<<sum<<endl;
        if(nums.size()==max+1&&count==2&&sum==a)return true;
        return false;
    }
};