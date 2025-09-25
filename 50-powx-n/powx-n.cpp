class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1.0000;
        }
        if(n%2==0){
            double ans=myPow(x,n/2);
            return ans*ans;
        }
        if(n<0){
        double ans=myPow(x,n+1);
         return ans/x;
        }
        return x*myPow(x,n-1);
    }
};