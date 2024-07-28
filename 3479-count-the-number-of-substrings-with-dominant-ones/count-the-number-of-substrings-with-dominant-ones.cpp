class Solution {
public:
    int numberOfSubstrings(string s) {
         
         vector<int>prefix(s.length(),0);
          int sum=0;
          int ans=0;
         for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                sum++;
            }
            prefix[i]=sum;
         }
        for(int i=0;i<s.length();i++){
             int count0=0;
        int count1=0;
           for(int j=i;j<s.length();j++){
               count1=prefix[j];
               if(i-1>=0){
                count1-=prefix[i-1];
               }
               count0=j-i+1-count1;
               if(count0*count0>count1){
                //meri condition false ho gayi
                 j+=count0*count0-count1-1;
           }
           else if(count0*count0<=count1){
                   ans++;
                if(count0*count0<count1){
                    int diff=sqrt(count1)-count0;
                    int nextj=j+diff;
                    if(nextj>=s.length()){
                        ans+=s.length()-j-1;
                    }
                    else{
                        ans+=diff;
                    }
                    j=nextj;
                }
                
           }
        }
        
    }
    return ans;
    }
};