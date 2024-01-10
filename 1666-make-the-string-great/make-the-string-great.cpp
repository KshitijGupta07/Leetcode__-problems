class Solution {
public:
    string makeGood(string s) {
        if(s.length()==1){
            return s;
        }
        string ans="";
        for(int i=0;i<s.length();){
           if(ans.size()==0){
               ans.push_back(s[i]);
               i++;
           }
           else{
               if(abs(ans[ans.size()-1]-s[i])==32){
                  ans.pop_back();
                  s.erase(s.begin()+i);
               }
               else{
                   ans.push_back(s[i]);
                   i++;
               }
           }

        }
        return ans;
    }
};