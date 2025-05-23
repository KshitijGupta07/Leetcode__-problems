class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int>lps(needle.length(),0);
        int i=1;
        int len=0;
        while(i<needle.length()){
            if(needle[i]==needle[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len>0){
                    len=lps[len-1];

                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        i=0;
        int j=0;
        while(i<haystack.length()&&j<needle.length()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==needle.length()){
                    return i-needle.length();
                }
            }
            else{
                if(j>0){
                    j=lps[j-1];
                }
                else{
                    lps[j]=0;
                    i++;
                }
            }
        }
        return -1;
    }
};