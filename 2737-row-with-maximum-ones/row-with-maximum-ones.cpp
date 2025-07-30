class Solution {
public:
   int binarysearch(vector<int>&nums,int target){
     int start=0;
     int end=nums.size()-1;
     if(nums[0]>target){
        return -1;
     }
     int ans=0;
     while(start<=end){
          int mid=(start+end)/2;
          if(nums[mid]>target){
            end=mid-1;
          }
          else{
            ans=mid;
            start=mid+1;
          }
     }
     return ans;
   }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxi=0;
        for(int i=0;i<mat.size();i++){
            sort(mat[i].begin(),mat[i].end());
            int a=mat[0].size()-(binarysearch(mat[i],0)+1);
            maxi=max(maxi,a);
        }
        
        
        int b=-1;
       for(int i=0;i<mat.size();i++){
        if(maxi==mat[0].size()-(binarysearch(mat[i],0)+1)){
            b=i;
            break;
        }
       }
       return {b,maxi};
    }
};