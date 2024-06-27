class Solution {
public:
    int appendCharacters(string s, string t) {
        int prefix=0;
        int trav=0;
        while(trav!=s.length()&&prefix!=t.length()){
            if(t[prefix]==s[trav]){
                prefix++;
                trav++;
            }
            else{
                trav++;
            }
        }
            if(prefix==0){
                return t.length();
            }
        
        return t.length()-prefix;
    }
};