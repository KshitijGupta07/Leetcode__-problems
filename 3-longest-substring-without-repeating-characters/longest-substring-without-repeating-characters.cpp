class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==1){
            return 1;
        }
        map<char,int>m;
        int l=0;
        int r=0;
        int ans=0;
        while(r<s.length()){
              m[s[r]]+=1;
              while(m[s[r]]>1){
                 m[s[l]]-=1;
                 if(m[s[l]]==0){
                    m.erase(s[l]);
                 }
                 l++;
              }
              ans=max(ans,r-l+1);
              r++;
        }

        return ans;
    }
};