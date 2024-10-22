class Solution {
public:
    char solve(int n,int k){
        if(n==1){
            return '0';
        }
        if(pow(2,n-1)==k){
            return '1';
        }
        if(k>pow(2,n-1)){
        int a= (solve(n,pow(2,n)-k))-'0';
         a=a^1;
         return a+'0';
        }
        return solve(n-1,k);
    }
    char findKthBit(int n, int k) {
        char ans=solve(n,k);
        return ans;
    }
};