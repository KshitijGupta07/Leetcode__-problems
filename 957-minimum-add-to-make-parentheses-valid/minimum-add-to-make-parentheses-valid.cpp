class Solution {
public:
    int minAddToMakeValid(string s) {
        string unvalid="";
        for(int i=0;i<s.length();i++){
            if(unvalid.empty()==true){
                unvalid.push_back(s[i]);
            }
            else{
                if(unvalid.back()=='('&&s[i]==')'){
                     unvalid.pop_back();
                }
                else{
                    unvalid.push_back(s[i]);
                }
            }
        }
        return unvalid.length();
    }
};