class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0){
            if(nums2.size()%2==0){
                return (double(nums2[nums2.size()/2])+double(nums2[nums2.size()/2 -1]))/2;
            }
            else{
               return (double(nums2[nums2.size()/2 ])); 
            }
        }
        if(nums2.size()==0){
             if(nums1.size()%2==0){
                return (double(nums1[nums1.size()/2])+double(nums1[nums1.size()/2 -1]))/2;
            }
            else{
               return (double(nums1[nums1.size()/2 ])); 
            }
        }
        vector<int>ans;
        int i=0;
        int j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]>nums2[j]){
                ans.push_back(nums2[j]);
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
            }
        }
        cout<<i<<" "<<j<<endl;
        if(i!=nums1.size()-1){
            for(int k=i;k<=nums1.size()-1;k++){
                ans.push_back(nums1[k]);
            }
        }
        if(j!=nums2.size()-1){
            for(int k=j;k<=nums2.size()-1;k++){
                ans.push_back(nums2[k]);
            }
        }
        if(i==nums1.size()-1){
            ans.push_back(nums1[nums1.size()-1]);
        }
        if(j==nums2.size()-1){
            ans.push_back(nums2[nums2.size()-1]);
        }
        if(ans.size()%2==0){
                   return (double(ans[ans.size()/2])+double(ans[ans.size()/2 -1]))/2;
            
            
        }
        else{
            return double(ans[ans.size()/2]);
        }
        return -1;
        
    }
};