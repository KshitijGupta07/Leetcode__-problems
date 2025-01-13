class Solution {
public:
    int minimumLength(string s) {
        if(s.length()<3){
            return s.length();
        }
        vector<int>hash(26,0);
        for(auto j:s){
            hash[j-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(hash[i]>0){
                ans+=2-hash[i]%2;
            }

        }
        return ans;
    }
};