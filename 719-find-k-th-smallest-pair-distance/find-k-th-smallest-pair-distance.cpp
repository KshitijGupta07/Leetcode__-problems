class Solution {
public:
int countpair(vector<int>&nums,int target){
    int left=0;
    int ans=0;
    for(int i=0;i<nums.size();i++){
       while(nums[i]-nums[left]>target){
        left++;
       }
            ans+=i-left;
    }
    return ans;
}
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums[nums.size()-1]-nums[0];
        while(start<end){
            int mid=start+(end-start)/2;
            if(countpair(nums,mid)<k){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        return start;
    }
};