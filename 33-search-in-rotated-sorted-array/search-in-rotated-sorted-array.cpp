class Solution {
public:
    int pivotelement(vector<int>&nums){
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(nums[mid]>nums[0]){
                start=mid+1;
            }
            else{
                end=mid;
            }
            
        }
        return end;
    }
    int search(vector<int>& nums, int target) {
        if(nums[pivotelement(nums)]==target){
            return pivotelement(nums);
        }
        if(nums.size()==1){
            if(nums[0]==target){
                return 0;
            }
            else{
                return -1;
            }
        }
        if(nums.size()==2){
            if(nums[0]==target){
                return 0;
            }
           else if(nums[1]==target){
                return 1;
            }
            else{
                return -1;
            }
        }
        
        if(pivotelement(nums)>0&&pivotelement(nums)<nums.size()){
        if(target>=nums[0]){
          int start=0;
          int end=pivotelement(nums)-1;
          while(start<=end){
              int mid=start+(end-start)/2;
              if(nums[mid]==target){
                  return mid;
              }
              else if(nums[mid]>target){
                    end=mid-1;
              }
              else{
                  start=mid+1;
              }
          }
          
        }
    else{
         int start=pivotelement(nums);
          int end=nums.size()-1;
          while(start<=end){
              int mid=start+(end-start)/2;
              if(nums[mid]==target){
                  return mid;
              }
              else if(nums[mid]>target){
                    end=mid-1;
              }
              else{
                  start=mid+1;
              }
          }
          
        }
    }
    
    cout<<pivotelement(nums)<<endl;
    if(pivotelement(nums)==0||pivotelement(nums)==nums.size()-1){
        int start=0;
          int end=nums.size()-1;
          while(start<=end){
              int mid=start+(end-start)/2;
              if(nums[mid]==target){
                  return mid;
              }
              else if(nums[mid]>target){
                    end=mid-1;
              }
              else {
                  start=mid+1;
              }
          }
         
          
    }
    
    if(pivotelement(nums)==0&&nums[0]>nums[1]&&nums[1]==target){
        return 1;
    }
    
    return -1;
    }
};