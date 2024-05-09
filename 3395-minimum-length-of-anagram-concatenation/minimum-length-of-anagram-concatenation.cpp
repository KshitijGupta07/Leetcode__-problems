class Solution {
public:
bool check(string& s, int k){
     vector<int>firstfreq(26,0);
     for(int i=0;i<k;i++){
       
        firstfreq[s[i]-'a']++;
        
     }
     for(int i=k;i<s.length();i+=k){
        vector<int>range(26,0);
        for(int j=i;j<i+k;j++){
          range[s[j]-'a']++;
        }
        for(int j=0;j<26;j++){
            if(firstfreq[j]!=range[j]){
                return false;
            }
        }
        
     }
     return true;
}
    int minAnagramLength(string s) {
        vector<int>hash(26,0);
        int sum=0;

        for(int i=0;i<s.length();i++){
            hash[s[i]-'a']++;
        }
        
        for(int i=1;i<s.length();i++){
             if(s.length()%i==0){
                
                bool flag=check(s,i);
                if(flag==true){
                    return i;
                }
             }
        }
        
        return s.length();
    }
};