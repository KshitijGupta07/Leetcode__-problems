class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        int i=0;
        while(num!=0){
           ans=ans+(1-num%2)*pow(2,i);
           num/=2;
           i++;
        }
        return ans;
    }
};