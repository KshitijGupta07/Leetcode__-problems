class Solution {
public:
    string intToRoman(int num) {
       
         vector<string>ans;
         int i=1;
         while(num>0){
            string element="";
            int digit=num%10;
              if(i==1){
                if(digit<4){
                   for(int j=1;j<=digit;j++){
                        element.push_back('I');
                   }
                   
                }
                else if(digit==4){
                    element="IV";
                }
                else if(digit<9){
                    element.push_back('V');
                    for(int j=1;j<=digit-5;j++){
                        element.push_back('I');
                    }
                }
                else if(digit==9){
                    element="IX";
                }
              }
              else if(i==2){
                        if(digit<4){
                   for(int j=1;j<=digit;j++){
                        element.push_back('X');
                   }
                   
                }
                else if(digit==4){
                    element="XL";
                }
                else if(digit<9){
                    element.push_back('L');
                    for(int j=1;j<=digit-5;j++){
                        element.push_back('X');
                    }
                }
                else if(digit==9){
                    element="XC";
                }
              }
              else if(i==3){
                   if(digit<4){
                   for(int j=1;j<=digit;j++){
                        element.push_back('C');
                   }
                   
                }
                else if(digit==4){
                    element="CD";
                }
                else if(digit<9){
                    element.push_back('D');
                    for(int j=1;j<=digit-5;j++){
                        element.push_back('C');
                    }
                }
                else if(digit==9){
                    element="CM";
                }
              }
              else if(i==4){
                   if(digit<4){
                   for(int j=1;j<=digit;j++){
                        element.push_back('M');
                   }
                   
                }
              
              }
              i+=1;
              ans.push_back(element);
              num/=10;
              element.clear();
         }
         string roman="";
         reverse(ans.begin(),ans.end());
         for(auto j:ans){
            roman+=j;
         }
         return roman;

    }
    
};