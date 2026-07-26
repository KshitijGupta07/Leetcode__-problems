class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.length()<str2.length()){
            return gcdOfStrings(str2,str1);
        }
        string temp="";
        string ans="";
        for(int i=0;i<str1.length();i++){
            temp.push_back(str1[i]);
            string x="";
            while(x.length()<str1.length()){
                x=x+temp;
            }
            if(x==str1){
                x="";
                while(x.length()<str2.length()){
                    x=x+temp;
                }
                if(x==str2){
                    ans=temp;
                }
            }
        }
        return ans;
    }
};