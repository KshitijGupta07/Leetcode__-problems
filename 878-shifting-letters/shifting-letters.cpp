class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<int>suffix(shifts.size());
        int element=0;
        for(int i=shifts.size()-1;i>=0;i--){
            element=(element%26+shifts[i]%26)%26;
            suffix[i]=element;
        }
          
         for(int i=0;i<s.length();i++){
             int num=s[i]-'a';
             num=(num+suffix[i])%26;
             s[i]='a'+num;
         }
         return s;
    }
};