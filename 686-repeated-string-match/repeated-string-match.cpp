class Solution {
public:
  int kmp(string s,string b){
       vector<int>lps(b.length(),0);
       int i=1;
       int len=0;
       while(i<b.length()){
        if(b[i]==b[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
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
       while(i<s.length()&&j<b.length()){
           if(s[i]==b[j]){
            i++;
            j++;
            if(j==b.length()){
                return true;
            }
           }
           else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
       }

       }
       return false;
  }
    int repeatedStringMatch(string a, string b) {
        if(a==b){
            return 1;
        }
        int count=1;
          string s=a;
          while(s.length()<b.length()){
            s+=a;
            count++;
          }
          if(s==b){
            return count;
          }
          if(kmp(s,b)){
            return count;
          }
          if(kmp(s+a,b)){
            return count+1;
          }
          return -1;

    }
};