class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int a=num1;
        int b=num2;
        vector<int>bit(32,0);
        int count=0;
        int i=0;
        while(a!=0){
        
            bit[i]=(a%2);
            i++;
            a=a/2;
        }
        reverse(bit.begin(),bit.end());
        while(b>0){
            if(b&1){
                count++;
            }
            b=b>>1;

        }
        int count2=0;
        for(int i=0;i<bit.size();i++){
            if(bit[i]==1){
                count2++;
            }
        }
        
      if(count2==count){
        return num1;
      }
      else if(count2<count){
        count-=count2;
        int ans=0;
        for(int i=31;i>=0;i--){
            if(bit[i]==0&&count>0){
            ans=ans|(1<<(31-i));
            count-=1;
            }
        }
        for(int i=0;i<32;i++){
            if(bit[i]==1&&count2>0){
                ans=ans|(1<<(31-i));
                count2-=1;
            }
        }
        return ans;
      }
      else{
        int ans=0;
          for(int i=0;i<32;i++){
            if(bit[i]==1&&count>0){
                ans=ans|(1<<(31-i));
                count-=1;
            }
          }
          return ans;
      }
       return 0;

            

    }
};