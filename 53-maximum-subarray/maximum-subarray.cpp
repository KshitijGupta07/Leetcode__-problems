class Solution {
public:
   int sum(vector<int>&nums,int i,int j,int mid){
      int s=0;
      int left=INT_MIN;
      int right=INT_MIN;
      for(int x=mid;x>=i;x--){
        s+=nums[x];
        left=max(left,s);
      }
      s=0;
      for(int x=mid+1;x<=j;x++){
        s+=nums[x];
        right=max(right,s);
      }
      
      
    return left+right;
   }
   int solve(vector<int>&nums,int i,int j){
    if(i>j){
       return  INT_MIN;
    }
    if(i==j){
        return nums[j];
    }
      int mid=(i+j)/2 ;
      int left=solve(nums,i,mid);
      int right=solve(nums,mid+1,j);
      int total=sum(nums,i,j,mid);
      
      return max(total,max(left,right));
   }
    int maxSubArray(vector<int>& nums) {
        int ans=solve(nums,0,nums.size()-1);
        int total=0;
        int maxi=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     total+=nums[i];
        //      maxi=max(maxi,total);
        //     cout<<total<<endl;
        //     if(total<0){
                  
        //            total=0;
        //     }
        // }
        // return maxi;
        return ans;
    }
};