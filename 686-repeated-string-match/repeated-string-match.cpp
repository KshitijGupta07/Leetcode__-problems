class Solution {
public:
  bool kps(string pattern,string t){
    int n=pattern.length();
    vector<int>lps(n,0);
       int i=1;
       int len=0;
       while(i<n){
           if(pattern[i]==pattern[len]){
        
            len++;
              lps[i]=len;
              i++;
           }
           else if(len>0){
              len=lps[len-1];
           }
           else{
               len=0;
               i++;
           }
       }
         
         i=0;
        int j=0;
        int count=0;
        while(i<t.length()){
            if(t[i]==pattern[j]){
                i++;
                j++;
                if(j==pattern.length()){
                    return true;
                }
            }
            else if(j>0){
                j=lps[j-1];
            }
            else{
                
                i++;
            }
        }
       return false;
   }
    int repeatedStringMatch(string a, string b) {
        string s=a;
        int count=1;
        while(s.length()<b.length()){
          s+=a;
          count++;
        }
        if(s==b){
            return count;
        }
        if(kps(b,s)){
            return count;
        }
         if(kps(b,s+a)){
            return count+1;
         }
        
        return -1;
    }
};