class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5){
            return 0;
        }
        int count=0;
        int i=1;
       while(n/pow(5,i)!=0){
          count+=n/pow(5,i);
          i++;
       }
       return count;
    }
};