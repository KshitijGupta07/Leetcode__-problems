class Solution {
public:
    int sumBase(int n, int k) {
       int sum=0;
       int ans=0;
       int i=0;
       while(n!=0){
           
           sum=sum+pow(10,i)*(n%k);
           n=n/k;
           i++;
       } 
       while(sum!=0){
         ans=ans+sum%10;
         sum=sum/10;
       }
       return ans;
    }
};