class Solution {
public:
    int mySqrt(int x) {
        if(x==1||x==0){
            return x;
        }
        int start=0;
        int end=x;
        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;
             if(x/mid < mid){
                end=mid-1;
             }
             else if(x/mid>=mid){
                    ans=mid;
                    start=mid+1;
             }
        }
        return ans;
    }
};