class Solution {
public:
    int myAtoi(string s) {
        int counter=0;
        int counter1=0;
        string number="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(number.length()>0){
                    break;
                }
                continue;
            }
            else if(s[i]=='-'){
                if(counter==0&&counter1==0){
                counter++;
                number.push_back(s[i]);
                }
                else{
                    break;
                }
            }
            else if(s[i]=='+'){
                if(counter1==0&&counter==0){
                counter1++;
                number.push_back(s[i]);
                }
                else{
                    break;
                }
            }
            else if(s[i]>='0'&&s[i]<='9'){
                if(counter1==0){
                    counter1++;
                }
                number.push_back(s[i]);
            }
            else{
                break;
            }
        }
        if(number.length()==0){
            return 0;
        }
      
        if(number.length()==1){
            if(number[0]=='-'){
                return 0;
            }
            if(number[0]=='+'){
                return 0;
            }
        }
            
            string x="";
            for(int i=0;i<number.length();i++){
                x.push_back(number[i]);
                if(x.length()>1){
                    long long n=stoll(x);
                    if(n>INT_MAX){
                        return INT_MAX;
                    }
                    if(n<INT_MIN){
                        return INT_MIN;
                    }
                }
            }
            return stoi(number);
        

    }
};