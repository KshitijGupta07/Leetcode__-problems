class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()==true){
            return 0;
        }
        stack<int>st;
        st.push(-1);
        int maxlen=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                st.pop();
                if(st.empty()==true){
                    st.push(i);
                }
                else{
                
                    int len=i-st.top();
                    maxlen=max(maxlen,len);
                }
            }
            else{
                st.push(i);
            }
        }
        return maxlen;
    }
};