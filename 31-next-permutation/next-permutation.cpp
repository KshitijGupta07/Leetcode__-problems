class Solution {
public:
   int minimum(int start,int end,vector<int>&nums){
    int miniindex=INT_MAX;
    int mini=INT_MAX;
    for(int i=start;i<end;i++){
             if(mini>nums[i]){
                mini=nums[i];
                miniindex=i;
             }
    }
    return miniindex;
   }
    void nextPermutation(vector<int>& nums) {
        int mini=INT_MAX;
        int x=-1;
        int y=-1;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]){
                
                        x=i;
                        y=j;
                    
                    
                
                    
                }
            }
        }
        if(x==-1&&y==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        cout<<x<<" "<<y<<endl;
        swap(nums[x],nums[y]);
        int k=min(x,y);
        for(int i=k+1;i<nums.size();i++){
               int a=minimum(i,nums.size(),nums);
               cout<<i<<" "<<a<<endl;
               if(a!=INT_MAX){
                swap(nums[a],nums[i]);
               }
        }
    }
};