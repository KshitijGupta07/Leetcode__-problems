class Solution {
public:
    int solve(int n){
        if(n==1||n==0){
            return 1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=solve(i)*solve(n-1-i);
        }
        return ans;
    }
    int numTrees(int n) {
        int ans=solve(n);
        return ans;
    }
};