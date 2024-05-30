class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        string ans="";
        for(int i=0;i<s.length();i++){
             if(s[i]==')'){
                string k="";
                while(st.top()!='('&&st.empty()==false){
                    k.push_back(st.top());
                    st.pop();
                }
                
                st.pop();
            for(int j=0;j<k.length();j++){
                st.push(k[j]);
            }
             }
             else{
                st.push(s[i]);
             }
                
            }

            while(st.empty()==false){
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        
    }
};