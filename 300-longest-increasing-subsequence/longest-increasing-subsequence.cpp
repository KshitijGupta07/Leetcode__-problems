class Solution {
public:
    int binarysearch(vector<int>&ans,int target){
         int start=0;
         int end=ans.size()-1;
         int x=0;
         while(start<=end){
            int mid=(start+end)/2 ;
            if(ans[mid]>=target){
                  x=mid;
                  end=mid-1;
            }
            else{
                start=mid+1;
            }
         }
         return x;
    }
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(ans.empty()){
                ans.push_back(nums[i]);
            }
            else{
                if(ans.back()<nums[i]){
                    ans.push_back(nums[i]);
                }
                else{
                    int index=binarysearch(ans,nums[i]);
                    ans[index]=nums[i];
                }
            }
        }
        return ans.size();
    }
};