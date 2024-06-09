class Solution {
public:
    int numberOfChild(int n, int k) {
        if(k<n){
            return k;
        }
        else{
            int round=(k/(n-1));
            if(round%2==0){
                return (k%(n-1));
            }
            else{
               return (n-1)-(k%(n-1));
            }
        }
        return -1;
    }
};