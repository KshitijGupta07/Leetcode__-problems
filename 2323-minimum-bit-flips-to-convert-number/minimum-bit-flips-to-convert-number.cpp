class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xo=(start^goal);
        int count=0;
        while(xo>0){
            if(xo%2==1){
                count++;
            }
            xo=xo>>1;
        }
        return count;

    }
};