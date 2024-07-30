class Solution {
public:
    int minimumDeletions(string s) {
        int count=0;
        string t="";
        for(int i=0;i<s.length();i++){
            if(t.empty()==true){
                t.push_back(s[i]);
            }
            else{
                if(t.empty()==false){
                    if(s[i]=='a'&&t[t.length()-1]=='b'){
                        t.pop_back();
                        
                        count++;
                    }
                    else{
                        t.push_back(s[i]);
                    }
                }
            }
        }
        return count;
    }
};