class Solution {
public:
    string largestOddNumber(string num) {
          int index=-1;
          for(int i=0;i<num.length();i++){
             int a=num[i]-'0';
             if(a%2==1){
                 index=i;
             }
          }
          if(index==-1){
            return "";
          }
          return num.substr(0,index+1);
          
    }
};