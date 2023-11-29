class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n!=0){
            int digit=n%2;
            if(digit&&1==1){
                  count++;
            }
            n=n/2;
        }
        return count;
    }
};