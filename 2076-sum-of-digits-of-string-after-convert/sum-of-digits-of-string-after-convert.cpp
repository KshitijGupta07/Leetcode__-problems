class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            if(s[i]-'a'+1<10){
                sum+=s[i]-'a'+1;
            }
            else{
                sum+=(s[i]-'a'+1)%10+(s[i]-'a'+1)/10;
            }
        }
        if(k==1){
            return sum;
        }
        
        int sum2=0;
        while(sum!=0){
            sum2+=sum%10;
            sum/=10;
        }
        if(k==2){
            return sum2;
        }
      
      
        int sum3=sum2/10 +sum2%10;
          if(k==3){
            return sum3;
        }
        int sum4=sum3/10 +sum3%10;
          return sum4;
        
        
    }
};