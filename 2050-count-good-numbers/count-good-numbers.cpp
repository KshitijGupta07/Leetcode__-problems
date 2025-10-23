class Solution {
public:
    const long long MOD=1000000007;
    long long solve(int x,long long y){
        if(y==0){
            return 1;
        }
        if(y==1){
            return x;
        }
        if(y%2==0){
            long long z=solve(x,y/2)%MOD;
            return (z%MOD*z%MOD)%MOD;
        }
        return (x* solve(x,y-1)%MOD)%MOD;
    }
    int countGoodNumbers(long long n) {
        long long a=(n/2)+(n%2);
        long long b=n-a;
        return (solve(5,a)%MOD * solve(4,b)%MOD)%MOD;
    }
};