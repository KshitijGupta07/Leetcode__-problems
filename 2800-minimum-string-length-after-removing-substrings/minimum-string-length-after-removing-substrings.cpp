class Solution {
public:
    int minLength(string s) {
        string t="";
        for(int i=0;i<s.length();i++){
            if(t.empty()){
                t.push_back(s[i]);
            }
            else{
                if(t.back()=='A'&&s[i]=='B'){
                    t.pop_back();
                }
                else if(t.back()=='C'&&s[i]=='D'){
                    t.pop_back();
                }
                else{
                    t.push_back(s[i]);
                }
            }
        }
        
        return t.length();
    }
};