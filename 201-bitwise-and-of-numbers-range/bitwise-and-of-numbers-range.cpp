class Solution {
public:
    int bits(int a){
        int count=0;
        while(a>0){
            a=a>>1;
            count+=1;
        }
        return count;
    }
    int rangeBitwiseAnd(int left, int right) {
        if(left==right){
            return left;
        }
          int a=bits(left);
          int b=bits(right);
          int count=0;
          while(left!=right){
            left=left>>1;
            right=right>>1;
             count++;
          }
          int ans=0;
          if(left==0){
            return 0;
          }
          while(left>0){
            int bit=(left&1);
            if(bit==1){
             ans=ans|(1<<(count));
            }
            count++;
            left=left>>1;
          }
          return ans;

    }
};