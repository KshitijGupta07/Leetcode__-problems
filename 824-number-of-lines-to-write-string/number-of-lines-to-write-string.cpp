class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int sum=0;
        int count=1;
        
        for(int i=0;i<s.length();i++){
          int ch=s[i]-'a';
          if((sum+widths[ch])>100){
            sum=widths[ch];
            count++;
          }
          else{
            sum+=widths[ch];
            
          }
        }
        return {count,sum};
    
    }
};