class Solution {
public:
int solve(int n,int k){
    if(n==1){
        return 0;
    }
    int totalelements=pow(2,n-1);
    int half=totalelements/2;
    if(k>half){
        return 1-solve(n,k-half);
    }
    return solve(n-1,k);
}
    int kthGrammar(int n, int k) {
        return solve(n,k);
    }
};