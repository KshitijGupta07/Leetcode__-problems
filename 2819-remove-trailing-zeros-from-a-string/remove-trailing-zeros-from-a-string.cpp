class Solution {
public:
    string removeTrailingZeros(string num) {
        
        if(num[num.length()-1]!='0'){
            return num;
        }
        int ans=0;
        for(int i=num.length()-1;i>=0;i--){
           if(num[i]!='0'){
               ans=i;
               break;
           }
        }
      return num.substr(0,ans+1);
    }
};