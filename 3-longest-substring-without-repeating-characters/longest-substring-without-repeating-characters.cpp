class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int l=0;
        int r=0;
        int ans=0;
        while(r<s.length()){
            m[s[r]]++;
            if(r-l+1==m.size()){
                ans=max(ans,r-l+1);
            }
            while(r-l+1>m.size()){
                m[s[l]]-=1;
                if(m[s[l]]==0){
                    m.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};