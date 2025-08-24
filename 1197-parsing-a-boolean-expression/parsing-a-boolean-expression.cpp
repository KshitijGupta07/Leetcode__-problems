class Solution {
public:
    bool parseBoolExpr(string expression) {
         stack<char>st;
         bool x=false;
          for(int i=0;i<expression.length();i++){
               if(expression[i]==','||expression[i]==' '){
                continue;
               }
               else if(expression[i]==')'){
                vector<char>val;
                char result;
                 while(st.empty()==false&&st.top()!='('){
                    val.push_back(st.top());
                    st.pop();
                 }
                 st.pop();
                 char op=st.top();
                 st.pop();
                  if(op=='!'){
                      if(val[0]=='t'){
                        result='f';
                      }
                      else{
                        result='t';
                      }
                  }
                  else if(op=='&'){
                    result='t';
                     for(auto j:val){
                        if(j=='f'){
                            result='f';
                            break;
                        }
                     }

                  }
                  else if(op=='|'){
                    result='f';
                    for(auto j:val){
                        if(j=='t'){
                            result='t';
                            break;
                        }
                    }
                  }
                  st.push(result);

               }
               else{
                st.push(expression[i]);
               }
          }
          return st.top()=='t';
    }
};