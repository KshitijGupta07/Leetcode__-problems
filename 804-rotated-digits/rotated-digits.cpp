class Solution {
public:
    int rotatedDigits(int n) {
       int ans=0;
       for(int i=1;i<=n;i++){
            int element=i;
            bool s=false;
            bool f=false;
            while(element>0){
                if(element%10==3||element%10==4||element%10==7){
                    s=true;
                    break;
                }
                
                element/=10;
            }
            element=i;
            while(element>0){
                if(element%10==2||element%10==5||element%10==6||element%10==9){
                    f=true;
                    break;
                }
                element/=10;
            }
            if(s==false&&f==true){
              ans++;

            }

       }
       return ans;
    }
};