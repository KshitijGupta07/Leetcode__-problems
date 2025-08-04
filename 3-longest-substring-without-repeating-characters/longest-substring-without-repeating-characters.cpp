class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.length();
        int ans=0;
        map<char,int>m;
        while(r<n){
            m[s[r]]++;
            if(r-l+1!=m.size()){
                while(r-l+1!=m.size()){
                    m[s[l]]--;
                    if(m[s[l]]==0){
                        m.erase(s[l]);
                    }
                    l++;
                }
            }
             ans=max(ans,r-l+1);
             r++;

        }
        return ans;
    }
};