class Solution {
public:
    bool isPowerOfFour(int n) {
        int count=0;
        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }
         while(n>1){
             if(n%2==0){
                 count++;
                 n=n/2;
             }
             else{
                 return false;
                 break;
             }


         }
         if(count%2==0){
             return true;
         }
         return false;

    }
};