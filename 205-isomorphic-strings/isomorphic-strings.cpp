class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<bool>v(256,false);
        vector<bool>v2(256,false);
        vector<char>m(256);
        for(int i=0;i<s.length();i++){
            cout<<int(t[i])<<endl;
             if(v[s[i]]==false){
                v[s[i]]=true;
                if(v2[t[i]]==false){
                m[s[i]]=t[i];
             }
             else{
                return false;
             }
             }
             else{
               if(m[s[i]]!=t[i]){
                  return false;
               }
             }
            v2[t[i]]=true; 
        }
        return true;
    }
};