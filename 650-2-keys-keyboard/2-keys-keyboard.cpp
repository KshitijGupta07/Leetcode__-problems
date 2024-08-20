class Solution {
public:
   int solve(int n,int length,int i){
      if(n<length){
        return 10000;
      }
      if(n==length){
        return 0;
      }
      int copypaste=2+solve(n,2*length,length);
      int paste=1+solve(n,length+i,i);
      return min(copypaste,paste);
   }
    int minSteps(int n) {
        if(n==1){
            return 0;
    }
    int length=1;
    int i=1;
    int ans=solve(n,length,i);
    return 1+ans;
    }
};