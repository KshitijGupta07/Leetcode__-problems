class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int x=m+n-1;
        while(i>-1&&j>-1){
            if(nums1[i]>nums2[j]){
                nums1[x]=nums1[i];
                i--;
            }
            else{
                nums1[x]=nums2[j];
                j--;
            }
            x--;
        }
        while(i>-1){
            nums1[x]=nums1[i];
            x--;
            i--;
        }
        while(j>-1){
            nums1[x]=nums2[j];
            x--;
            j--;
        }
        return;
    }
};