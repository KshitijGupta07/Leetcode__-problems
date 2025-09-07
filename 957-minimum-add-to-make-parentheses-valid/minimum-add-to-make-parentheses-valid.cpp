class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(st.empty()==true){
                
                if(s[i]=='('){
                    st.push(s[i]);
                }
                else{
                    count++;
                }
                
            }
            else{
                if(s[i]==')'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        return st.size()+count;
    }
};