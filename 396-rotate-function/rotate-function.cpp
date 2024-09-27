class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        int s=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]*i;
            s+=nums[i];
        }
        int a=sum;
        int ans=INT_MIN;
        ans=max(a,ans);
        for(int i=nums.size()-1;i>=1;i--){
            sum=sum+s-n*nums[i];
              ans=max(ans,sum);
              
              
              cout<<sum<<endl;
        }
        if(nums.size()==1){
            return 0;
        }
        return ans;

    }
};