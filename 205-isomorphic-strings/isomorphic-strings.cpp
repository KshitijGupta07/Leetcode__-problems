class Solution {
public:
    bool isIsomorphic(string s, string t) {
     
        map<char,char>m;
        map<char,bool>c;
        for(int i=0;i<s.length();i++){
           
    
          if(m[s[i]]-'0'>=0&&m[s[i]]!=t[i]){
                return false;
          }
           if(c[t[i]]==true&&m[s[i]]!=t[i]){
            return false;
           }
           if(c[t[i]]==false){
                      m[s[i]]=t[i];
                      c[t[i]]=true;
           }
           
        
            
        }
           
    
    return true;
    }
};