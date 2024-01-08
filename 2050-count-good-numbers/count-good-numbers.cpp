class Solution {
public:
     long long  power(long long  a,long long n){
    int element=pow(10,9)+7;
         if(n==0){
             return 1;
         }
         if(n%2==0){
             long long ans=power(a,n/2)%element;
             return (ans%element*ans%element);
         }
       long long   ans=power(a,n-1)%element;
         return (ans*a)%element;
     }
    int countGoodNumbers(long long n) {
        int element=(pow(10,9)+7);
        if(n%2==0){
            return (power(20,n/2))%element;
        }
        return (power(5,n/2 +1)*power(4,n/2))%element;
    }
};