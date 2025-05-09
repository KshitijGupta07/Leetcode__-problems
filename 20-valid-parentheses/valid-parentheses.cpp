class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(auto j:s){
            if(st.empty()==true){
                st.push(j);
            }
            else{
                if(st.top()=='('&&j==')'){
                    st.pop();
                }
                else if(st.top()=='['&&j==']'){
                    st.pop();
                }
                else if(st.top()=='{'&&j=='}'){
                    st.pop();
                }
                else{
                    st.push(j);
                }
            }
        }
        return st.empty();
    }
};