class Solution {
public:
    int rev(vector<int>&nums,int start,int mid,int end){
        int count=0;
      int  i=start;
       int j=mid+1;
       for( i=start;i<=mid;i++){
        while(j<=end&&nums[i]>2LL*nums[j]){
            j++;
        }
        count+=(j-mid-1);
       }
        vector<int>left(mid-start+1);
        vector<int>right(end-mid);
        int k=start;

        for(int i=0;i<left.size();i++){
                left[i]=nums[k];
                k++;
        }
        k=mid+1;
        for(int i=0;i<right.size();i++){
          right[i]=nums[k];
          k++;
        }
         i=0;
         j=0;
        k=start;
        while(i<left.size()&&j<right.size()){
             if(left[i]<=right[j]){
                nums[k]=left[i];
                i++;
             }
             else{
               nums[k]=right[j];
               j++;
             }
             k++;
        }
        while(i<left.size()){
            nums[k]=left[i];
            i++;
            k++;
        }
        while(j<right.size()){
            nums[k]=right[j];
            j++;
            k++;
        }
      
        return count;
    }
    int solve(vector<int>&nums,int start,int end){
        if(start>=end){
            return 0;
        }
        int mid=(start+end)/2;
        int left=solve(nums,start,mid);
        int right=solve(nums,mid+1,end);
        int ans=rev(nums,start,mid,end);
        return ans+left+right;
    }
    int reversePairs(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int ans=solve(nums,start,end);
        return ans;
    }
};