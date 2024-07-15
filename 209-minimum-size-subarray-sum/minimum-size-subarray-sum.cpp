class Solution {
public:
   int binarysearch(vector<int>&nums,int target){
    int start=0;
    int end=nums.size()-1;
    bool flag=false;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]==target){
            flag=true;
            return mid;
        }
        else if(nums[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    if(flag==false){
        
        return start-1;
        
    }
    return -1;
   }
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int>prefix;
        int element=0;
        for(int i=0;i<nums.size();i++){
             element+=nums[i];
             prefix.push_back(element);

        }
        int mini=INT_MAX;
        
        for(int i=0;i<prefix.size();i++){
            if(prefix[i]==target){
                mini=min(mini,i+1);
                 
            }
            else if(prefix[i]>target){
                cout<<binarysearch(prefix,prefix[i]-target)<<endl;
             mini=min(mini,i-binarysearch(prefix,prefix[i]-target));
            }
                
                
            
        }
        if(mini==INT_MAX){
            return 0;
        }
        return mini;
    }
};