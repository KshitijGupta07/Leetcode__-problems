class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5){
            return 0;
        }
        int count=0;
        int element=5;
       while(n/element!=0){
          count+=n/element;
          element*=5;
          
       }
       return count;
    }
};