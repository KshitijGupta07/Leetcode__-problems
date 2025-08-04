class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int ans=0;
        int a=k;
        while(r<nums.size()){
            if(nums[r]==1){
                r++;
            }
            else{
                if(a>0){
                    r++;
                    a-=1;
                }
                else{
                    ans=max(ans,r-l+1);
                    while(a==0){
                        if(nums[l]==0){
                            a++;
                        }
                        l++;
                    }

                }
            }
        }
        ans=max(ans,r-l+1);
        return ans -1;
    }
};