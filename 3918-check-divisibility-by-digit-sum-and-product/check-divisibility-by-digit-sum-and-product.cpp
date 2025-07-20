class Solution {
public:
   int sum(int n){
      int s=0;
      while(n>0){
        s+=n%10;
        n=n/10;
      }
      return s;
   }
   int product(int n){
    int s=1;
    while(n>0){
        s*=n%10;
        n=n/10;
    }
    return s;
   }
    bool checkDivisibility(int n) {
        cout<<sum(n)<<" "<<product(n)<<endl;
      int total=sum(n)+product(n);
      return n%total==0;
    }
};