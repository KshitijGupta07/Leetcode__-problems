class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            int mid=(start+end)/2;
            if(mid+1<nums.size()&&mid-1>=0&&nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            else if(mid==0&&nums[0]!=nums[1]){
                return nums[0];
            }
            else if(mid==0&&nums[0]==nums[1]){
                start=mid+1;
            }
            else if(mid==nums.size()-1&&nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            else if(mid==nums.size()-1&&nums[mid]==nums[mid-1]){
                end=mid-1;
            }
            else{
                
                if(mid-1>=0&&nums[mid]==nums[mid-1]){
                    if(mid%2==0){
                        end=mid-1;
                    }
                    else{
                       start=mid+1; 
                    }
                }
                else if(mid+1<nums.size()&&nums[mid]==nums[mid+1]){
                    if(mid%2==1){
                        end=mid-1;
                    }
                    else{
                        start=mid+1;
                    }
                }
            }
        }
        
        return nums[start];
    }
};