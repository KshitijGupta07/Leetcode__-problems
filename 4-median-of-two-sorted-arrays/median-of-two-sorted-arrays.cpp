class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         double x=0;
         double y=0;
         int i=0;
         int j=0;
         int m=nums1.size();
         int n=nums2.size();
        int count=(m+n)/2 ;
        while(count>=0){
            y=x;
            if(i<m&&j<n){
                if(nums1[i]>nums2[j]){
                    x=nums2[j];
                    j++;
                }
                else{
                    x=nums1[i];
                    i++;
                }
            }
            else if(i<m){
                x=nums1[i];
                i++;
            }
            else{
                x=nums2[j];
                j++;
            }
            
            count--;
        }
        count=(m+n) ;
        if(count%2==1){
            return max(x,y)/1.000 ;
        }
        
    
        return (x+y)/2.000;
    }
};