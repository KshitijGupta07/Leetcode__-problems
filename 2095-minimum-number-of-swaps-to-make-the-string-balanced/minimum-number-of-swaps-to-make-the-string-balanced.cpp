class Solution {
public:
    int minSwaps(string s) {
        string t="";
        for(int i=0;i<s.length();i++){
            if(t.empty()){
                t.push_back(s[i]);
            }
            else{
                if(t.back()=='['&&s[i]==']'){
                    t.pop_back();
                }
                else{
                    t.push_back(s[i]);
                }
            }
        }
        int a=t.length()/2 ;

    
        return a/2 +a%2;
    }
};