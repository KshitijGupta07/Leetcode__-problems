class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.length()<str2.length()){
            return gcdOfStrings(str2,str1);
        }
        int m=str1.length();
        int n=str2.length();
        int len=__gcd(m,n);
        string ans="";
        for(int i=0;i<len;i++){
            ans.push_back(str1[i]);
        }
        string x="";
        while(x.length()<str1.length()){
            x=x+ans;
        }
        if(x==str1){
            x="";
            while(x.length()<str2.length()){
                x=x+ans;
            }
            if(x==str2){
                return ans;
            }
        }
        return "";
    }
};