class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0;i<tokens.size();i++){
            if(s.empty()==true){
                if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/"){
                    
                
                
                    s.push(stoi(tokens[i]));
                }
                    
                
            }
            
            else{
                 if((tokens[i]!="+")&&(tokens[i]!="-")&&(tokens[i]!="*")&&(tokens[i]!="/")){
                     s.push(stoi(tokens[i]));
                     
                 }
                 else{
                     if(tokens[i]=="+"){
                         int a=s.top();
                         s.pop();
                         int b=s.top();
                         s.pop();
                         s.push(a+b);
                     }
                     if(tokens[i]=="*"){
                         int a=s.top();
                         s.pop();
                         int b=s.top();
                         s.pop();
                         s.push(a*b);
                     }
                     if(tokens[i]=="-"){
                         int a=s.top();
                         s.pop();
                         int b=s.top();
                         s.pop();
                         s.push(b-a);
                     }
                     if(tokens[i]=="/"){
                         int a=s.top();
                         s.pop();
                         int b=s.top();
                         s.pop();
                         s.push(b/a);
                     }
                     
                 }
            }
            cout<<s.top()<<endl;
        }
        return s.top();
    }
};