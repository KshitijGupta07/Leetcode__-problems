class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int ans=0;
        for(int i=0;i<s.length();i++){
             if(s[i]==')'){
                st.pop();
                if(st.empty()==true){
                    st.push(i);
                }
                else{
                    ans=max(ans,i-st.top());
                }

             }
             else{
                st.push(i);
             }
        }
        return ans;
    }
};