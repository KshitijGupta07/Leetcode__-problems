class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            
            if(s[i]>='a'&&s[i]<='z'){
                ans.push_back(s[i]);
            }
            else{
                int q=ans.length()-1;
                if((ans[q]>='a'&&ans[q]<='z')&&(s[i]>='0'&&s[i]<='9')){
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};