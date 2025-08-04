class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int ans=0;
        int maxf=0;
        vector<int>hash(26,0);
        while(r<s.length()){
           hash[s[r]-'A']+=1;
            maxf=max(maxf,hash[s[r]-'A']);
            while(r-l+1-maxf>k){
                hash[s[l]-'A']-=1;
                l++;
                for(auto j:hash){
                    maxf=max(maxf,j);
                }
            }
            ans=max(ans,r-l+1);
            r++;
            
        }
        return ans;
    }
};