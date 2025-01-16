class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
          int ans=0;
            for(int i=0;i<nums2.size();i++){
                ans=ans^nums2[i];
            }
        
            int ans2=0;
            for(int i=0;i<nums1.size();i++){
                  ans2=ans2^nums1[i];
            }
        if(nums1.size()%2==0&&nums2.size()%2==0){
            return 0;
        }
       
          
            else if(nums1.size()%2==1&&nums2.size()%2==1){
                return ans^ans2;
            }
            else if(nums1.size()%2==1){
                return ans;
            }
            return ans2;

        

    }
};