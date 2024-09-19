class Solution {
public:
    int calculate(string s) {
        
        int number=0;
        int result=0;
        int signal=1;
        stack<int>op;
        for(int i=0;i<s.length();i++){
             char ch=s[i];
             if(isdigit(ch)){
                number=number*10+(ch-'0');
             }
             else if(ch=='+'||ch=='-'){
                  result+=number*signal;
                  if(ch=='-'){
                    signal=-1;
                  }
                  else{
                    signal=1;
                  }
                  
                  number=0;
             }
             else if(ch=='('){
                op.push(result);
                op.push(signal);
                result=0;
                signal=1;
             }
             else if(ch==')'){
                result+=number*signal;
                
                
                
                result*=op.top();
                op.pop();
                result+=op.top();
                op.pop();
                
                number=0;
             }
        }
        return result+number*signal;
    }
};