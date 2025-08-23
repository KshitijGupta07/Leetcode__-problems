class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        vector<string>te;
        string temp="";
        for(int i=0;i<s.length();i++){
            if(st.empty()==true){
                te.push_back(temp);
                temp="";
                st.push(s[i]);
                temp.push_back(s[i]);
            }
            else{
                if(st.top()=='('&&s[i]==')'){
                    st.pop();
                    
                }
                else{
                    st.push(s[i]);
                }
                
                temp.push_back(s[i]);
            }
        }
        te.push_back(temp);
        te.erase(te.begin());
        string ans="";
        for(auto j:te){
               j.erase(j.begin());
               j.pop_back();
               ans+=j;
        }
        return ans;
    }
};