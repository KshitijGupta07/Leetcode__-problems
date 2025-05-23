class Solution {
public:
    int strStr(string haystack, string needle) {
        // vector<int>lps(needle.length(),0);
        // int i=1;
        // int len=0;
        // while(i<needle.length()){
        //     if(needle[i]==needle[len]){
        //         len++;
        //         lps[i]=len;
        //         i++;
        //     }
        //     else{
        //         if(len>0){
        //             len=lps[len-1];

        //         }
        //         else{
        //             lps[i]=0;
        //             i++;
        //         }
        //     }
        // }
        // i=0;
        // int j=0;
        // while(i<haystack.length()&&j<needle.length()){
        //     if(haystack[i]==needle[j]){
        //         i++;
        //         j++;
        //         if(j==needle.length()){
        //             return i-needle.length();
        //         }
        //     }
        //     else{
        //         if(j>0){
        //             j=lps[j-1];
        //         }
        //         else{
        //             lps[j]=0;
        //             i++;
        //         }
        //     }
        // }
        // return -1;
        //Z-ALGO
        int l=0;
        int r=0;
        string x=needle +"$" +haystack;
        vector<int>z(x.length(),0);
        for(int i=1;i<x.length();i++){
            if(r>=i){
                z[i]=min(z[i-l],r-i+1);
            }
            while(i+z[i]<x.length()&&x[z[i]]==x[z[i]+i]){
                z[i]++;
            }
            if(i+z[i]-1>r){
                l=i;
                r=i+z[i]-1;
            }
        }
        for(auto j:z){
            cout<<j<<" ";
        }
        for(int i=0;i<z.size();i++){
            if(z[i]==needle.length()){
                return i-needle.length()-1;
            }
        }
        return -1;
    }
};