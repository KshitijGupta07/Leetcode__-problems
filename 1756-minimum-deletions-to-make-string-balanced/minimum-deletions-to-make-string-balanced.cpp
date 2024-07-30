class Solution {
public:
    int minimumDeletions(string s) {
        int count=0;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(st.empty()==true){
                st.push(s[i]);
            }
            else{
                if(st.empty()==false){
                    if(s[i]=='a'&&st.top()=='b'){
                        st.pop();
                        
                        count++;
                    }
                    else{
                        st.push(s[i]);
                    }
                }
            }
        }
        return count;
    }
};