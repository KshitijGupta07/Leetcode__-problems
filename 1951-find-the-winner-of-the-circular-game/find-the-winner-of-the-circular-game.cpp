class Solution {
public:
  int winner(int n,int k){
    if(n==1){
        return 1;
    }
    return (winner(n-1,k)+k-1)%n +1;
  }
    int findTheWinner(int n, int k) {
         int ans=winner(n,k);
         return ans;
    }
};