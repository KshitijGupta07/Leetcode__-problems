class Solution {
public:
   void merge(vector<pair<int,int>>&nums,int start,int mid,int end,vector<int>&ans){
      vector<pair<int,int>>temp;
      int i=start;
      int j=mid+1;
      while(i<=mid&&j<=end){
        if(nums[i].first>nums[j].first){
            temp.push_back(nums[i]);
            ans[nums[i].second]+=end-j+1;
            i++;
        }
        else{
            temp.push_back(nums[j]);
            
            j++;
        }
      }
      cout<<i<<" "<<j<<endl;
      while(i<=mid){
        
        temp.push_back(nums[i]);
        i++;
      }
      while(j<=end){
        temp.push_back(nums[j]);
        j++;
      }
      int k=0;
    for(int i=start;i<=end;i++){
        nums[i]=temp[k];
        k++;
    }

   }
   void divide(vector<pair<int,int>>&nums,int start,int end,vector<int>&ans){
    if(start<end){
        int mid=start+(end-start)/2;
        divide(nums,start,mid,ans);
        divide(nums,mid+1,end,ans);
        merge(nums,start,mid,end,ans);
    }
   }
    vector<int> countSmaller(vector<int>& nums) {
         vector<pair<int,int>>v;
         for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
         }
         vector<int>ans(nums.size());
         divide(v,0,nums.size()-1,ans);
         return ans;
    }
};