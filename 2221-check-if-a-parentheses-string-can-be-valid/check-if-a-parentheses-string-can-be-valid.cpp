class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()%2==1){
            return false;
        }
        stack<int>open,unlock;
        for(int i=0;i<s.length();i++){
            
            if(locked[i]=='0'){
                unlock.push(i);
            }
           else if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]==')'){
                if(open.empty()==false){
                    open.pop();
                }
                else if(unlock.empty()==false){
                    unlock.pop();
                }
                else {
                    return false;
                }
            }
           }
           while(unlock.empty()==false&&open.empty()==false&&unlock.top()>open.top()){
               unlock.pop();
               open.pop();
           }
           if(open.empty()==false){
            return false;
           }
           return true;
    }
};