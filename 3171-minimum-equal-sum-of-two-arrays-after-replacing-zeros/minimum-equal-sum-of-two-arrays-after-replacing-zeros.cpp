class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long a=0;
        long long b=0;
        int  count1=0;
        int  count2=0;
        for(int i=0;i<nums1.size();i++){
           a+=nums1[i];
           

        }
        for(int i=0;i<nums2.size();i++){
            b+=nums2[i];
        }
        
            for(int i=0;i<nums1.size();i++){
                if(nums1[i]==0){
                    nums1[i]=1;
                    count1++;
                }
            }
            for(int i=0;i<nums2.size();i++){
                if(nums2[i]==0){
                    nums2[i]=1;
                    count2++;
                }
            }
            if(count1==0&&b+count2>a){
                 return -1;
            }
            if(count2==0&&a+count1>b){
                return -1;
            }
             if(count1==0){
                return max(b+count2,a);
            }
            if(count2==0){
                return max(a+count1,b);
            }
            if(count1!=0&&count2!=0){
                return max(a+count1,b+count2);
            }

            
        return -1;
        
        
    }
};