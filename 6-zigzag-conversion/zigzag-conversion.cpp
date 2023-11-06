class Solution {
public:
    string convert(string s, int numRows) {
        string ans="";
        if(numRows==1){
            return s;
        }
        if(numRows>1){
        for(int count=0;count<numRows;count++){
          for(int i=0;i<s.length();i++){
              if(i%(2*numRows-2)==count||i%(2*numRows-2)==2*numRows-2-count){
                  ans.push_back(s[i]);
              }
          }
        }
    }
        return ans;
    }
};