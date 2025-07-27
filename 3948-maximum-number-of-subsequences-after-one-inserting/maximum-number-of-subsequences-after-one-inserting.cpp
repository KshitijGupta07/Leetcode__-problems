class Solution {
public:
    long long numOfSubsequences(string s) {
        vector<long long >prefix(s.length()+1,0);
        vector<long long >suffix(s.length()+1,0);
    
        for(int i=0;i<s.length();i++){
               if(s[i]=='L'){
                  prefix[i+1]=1;
               }
               prefix[i+1]+=prefix[i];
        }
        
        for(int i=s.length()-1;i>=0;i--){
               if(s[i]=='T'){
                suffix[i]=1;
               }
               suffix[i]+=suffix[i+1];
        }
        long long L=0;
        long long C=0;
        long long R=0;
        long long best=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='C'){
              C+=prefix[i]*suffix[i+1];
              L+=(prefix[i]+1)*suffix[i+1];
              R+=(suffix[i+1]+1)*(prefix[i]);
            }
            else{
                best=max(prefix[i]*suffix[i],best);
            }
        }
        C+=best;
        return max(L,max(C,R));

    }
};