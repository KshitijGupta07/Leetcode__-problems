class Solution {
public:
    long long  solve(long long  a,long long  x){
        if(x==0){
            return 1;
        }
        if(x==1){
            return a;
        }
        long long  element=pow(10,9)+7;

        if(x%2==0){
            long long  c=solve(a,x/2)%element;
            return( c%element * c%element)%element;
        }
        long long  b=(a*solve(a,x-1)%element)%element;
        return b%element;
    }
    int countGoodNumbers(long long n) {
        int element=pow(10,9)+7;
        long long  ans=solve(4,n/2)%element;
        long long   ans2=solve(5,n-n/2)%element;
        
        return (ans%element*ans2%element)%element;
    }
};