class Solution {
public:
    bool isAnagram(string s, string t) {
         if(s.length()!=t.length())return false;
         vector<int>hash1(26,0);
         vector<int>hash2(26,0);
         for(int i=0;i<s.length();i++){
              hash1[s[i]-'a']+=1;
              hash2[t[i]-'a']+=1;
         }
         for(int i=0;i<26;i++){
             if(hash1[i]!=hash2[i]){
                return false;
             }
         }
         return true;
    }
};