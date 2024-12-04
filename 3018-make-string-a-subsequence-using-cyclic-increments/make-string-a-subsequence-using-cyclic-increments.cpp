class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0;
        int j=0;
        while(i<str1.length()&&j<str2.length()){
             if(str1[i]==str2[j]||str2[j]-str1[i]==1||(str2[j]=='a'&&str1[i]=='z')){
                i++;
                j++;
             }
             else{
                i++;
             }
        }
        if(j<str2.length()){
            return false;
        }
        return true;
    }
};