class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=x;
        long long unset=1;
        long long set=1;
        n=n-1;
        while(set<=n){
            if((unset&x)==0){
                if(set&n){
                   ans=ans|unset;
                   
                }
                set=set<<1;
            }
           unset= unset<<1;
        }
        return ans;
    }
};