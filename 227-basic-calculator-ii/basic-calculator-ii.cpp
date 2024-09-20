class Solution {
public:
    int calculate(string s) {
        stack<char>st;
        stack<int>num;
        int number=0;
        int signal=1;
        int counter=0;
        for(int i=0;i<s.length();i++){
           if(isdigit(s[i])){
            number=number*10+(s[i]-'0');
           }
           else if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'){
            num.push(number);
            number=0;
                 if(st.empty()==false){
                      if(st.top()=='*'||st.top()=='/'){
                        int a=num.top();
                        num.pop();
                        int b=num.top();
                        
                        num.pop();
                        if(st.top()=='*'){
                            
                        num.push(a*b);
                        }
                        if(st.top()=='/'){
                            num.push(b/a);
                        }
                        counter++;
                        st.pop();
                        counter--;
                        
                  
                        
                      }
                    
                         
                 }
                 st.push(s[i]);
               }
               
               
           }
        num.push(number);
        if(num.size()==1){
            return num.top();
        }
        if(st.top()=='*'){
            int a=num.top();
            num.pop();
            int b=num.top();
            num.pop();
            num.push(a*b);
            st.pop();
        }
       else if(st.top()=='/'){
            int a=num.top();
            num.pop();
            int b=num.top();
            num.pop();
            num.push(b/a);
            st.pop();
        }
        if(num.size()==1){
            return num.top();
        }
        int ans=0;
        while(num.empty()==false&&st.empty()==false){
            cout<<num.top()<<" "<<st.top()<<endl;
            if(st.top()=='+'){
                ans+=num.top();
            }
            if(st.top()=='-'){
                ans-=num.top();
            }
            num.pop();
            st.pop();
        }
        cout<<num.size()<<endl;
       
   return ans+num.top();;
    }
};