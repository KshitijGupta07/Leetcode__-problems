class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        
        if(nums1[0]>nums2[nums2.size()-1]){
            return -1;
        }
        if(nums2[0]>nums1[nums1.size()-1]){
            return -1;
        }
        if(nums1[0]==nums2[0]){
            return nums1[0];
        }
        for(int i=0,j=0;i<nums1.size()&&j<nums2.size();){
            if(nums1[i]==nums2[j]){
                return nums1[i];
                break;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return -1;

    }
};