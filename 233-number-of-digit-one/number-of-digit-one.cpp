class Solution {
public:
int length(int n){

    int count=0;
    while(n!=0){
       count++;
       n/=10;
    }
    return count;
}
    int countDigitOne(int n) {
            if(n==0){
        return 0;
}
   else if(n<=9){
    return 1;
   }
        int len=length(n);
        int base=pow(10,len-1);
        int mul=n/base;
        int addbase=0;
        if(mul==1){
            addbase=n-base+1;
        }
        else{
            addbase=base;
        }
        int rem=n%base;
        return countDigitOne(base-1)*mul+addbase+countDigitOne(rem);
    }
};