class Solution {
public:
    bool isFascinating(int n) {
       string a=to_string(n)+to_string(2*n)+to_string(3*n);
       
       long ans=stoll(a);
       int multi=1;
        while(ans!=0){
          multi=multi*(ans%10);
          ans=ans/10;
        }
        if(multi==362880){
            return true;
        }
        return false;
           
    }
};