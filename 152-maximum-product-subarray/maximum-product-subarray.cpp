class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int p=1;
        for(int i=0;i<nums.size();i++){
             p*=nums[i];
             ans=max(ans,p);
             if(p==0){
                p=1;
             }
        }
        int ans2=INT_MIN;
        p=1;
        for(int i=nums.size()-1;i>=0;i--){
                  p*=nums[i];
             ans2=max(ans2,p);
             if(p==0){
                p=1;
             }
        }
        return max(ans,ans2);
    }
};