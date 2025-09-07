class Solution {
public:
    bool rotateString(string s, string goal) {
       int count=1;
       while(count<=s.length()){
          char ch=s[0];
          s.erase(s.begin());
          s.push_back(ch);
          if(s==goal){
            return true;
          }
          count++;
       }
       return false;
    }
};