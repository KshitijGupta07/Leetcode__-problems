class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        int start=0;
        int end=m;
        int total=(m+n+1)/2;
        while(start<=end){
            int mid=(start+end)/2;
            int mid2=total-mid;
            
            int r1=INT_MAX;
            
            int r2=INT_MAX;
            if(mid<m){
                r1=nums1[mid];
            }
            if(mid2<n){
                r2=nums2[mid2];
            }
            int l1=INT_MIN;
            int l2=INT_MIN;
            if(mid-1>=0){
                 l1=nums1[mid-1];
            }
            if(mid2-1>=0){
                l2=nums2[mid2-1];
            }
            if(l1<=r2&&l2<=r1){
                if((m+n)%2==0){
                    l1=max(l1,l2);
                    r1=min(r1,r2);
                    return ((l1+r1)/2.00);
                }
                else{
                    return max(l1,l2)/1.00;
                }
            }
            else if(l1>r2){
                   end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return 0.000;
    }
};