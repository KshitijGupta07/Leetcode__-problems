class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)return 1;
        int firsterm=1;
        int lasterm=n;
        int diff=2;
        int a=1;
        while(n>1){
            if(a%2==1){
                int mod=firsterm%diff;
                firsterm=firsterm+diff/2;
                if(lasterm%diff==mod){
                   lasterm=lasterm-diff/2;
                }

            } 
            else{
               int mod=lasterm%diff;
               lasterm=lasterm-diff/2;
               if(firsterm%diff==mod){
                firsterm=firsterm+diff/2;
               }
            }
            a++;
            diff*=2;
            n=n/2;
        }
        if(a%2==0){
            return min(firsterm,lasterm);
        }
        return max(firsterm,lasterm);
        return 0;
    }
};