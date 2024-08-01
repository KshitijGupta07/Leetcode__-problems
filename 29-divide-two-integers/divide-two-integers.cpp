class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN){
            if(divisor==-1){
                return INT_MAX;
            }
            if(divisor==1){
                return INT_MIN;
            }
        }
        if(dividend==INT_MAX){
           if(divisor==1){
            return INT_MAX;
           }
           if(divisor==-1){
            return INT_MIN+1;
           }
        }
        long a=abs(dividend);
        long b=abs(divisor);
        int ans=0;
        while(a>=b){
          
        
            int count=1;
              long element=b;
            while(element<<1 <=a){
                cout<<element<<endl;
               element<<=1;
                count<<=1;
            }
            a-=element;
            ans+=count;
        }
        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)){
            return -ans;
        }
        return ans;
    }
};