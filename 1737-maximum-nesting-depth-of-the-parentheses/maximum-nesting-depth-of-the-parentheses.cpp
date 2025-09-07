class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(st.empty()==true){
                if(s[i]=='('){
                    st.push('(');
                }
            }
            else{
                if(s[i]=='('){
                    st.push('(');
                }
                else if(s[i]==')'){
                      int a=st.size();
                      ans=max(ans,a);
                      st.pop();
                }
            }
        }
        return ans;
    }
};