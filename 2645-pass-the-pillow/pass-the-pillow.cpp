class Solution {
public:
    int passThePillow(int n, int time) {
         if(time<n){
            return time+1;
         }
        int a=n-1;
        if((time/a)%2==0){
            return time%a +1;
        }
        return n- time%a;
         
    }
};