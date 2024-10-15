class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        long long count=0;
        for(long long i=0;i<s.length();i++){
            if(s[i]=='0'){
               
                ans+=i-count;
                 count=count+1;
            }
        }
        return ans;
    }
};