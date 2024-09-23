class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long element=pow(10,9)+7;
        long long  lcm=(a*b)/__gcd(a,b);
        long long  low=min(a,b);
        long long N=n;
        long long high=N*min(a,b);
       
        while(low<high){
            long long mid=(low+high)/2 ;
             long long c=mid/a +mid/b -mid/lcm;
             if(c<n){
                low=mid+1;
             }
             else{
                 high=mid;
             }
        }
        return low%element;

    }
};