class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int maxlen=0;
        int length=0;
        vector<int>hash(255,-1);
        while(right<s.length()){
            if(hash[s[right]]!=-1){
                if(hash[s[right]]>=left){
                left=hash[s[right]]+1;
            }
            }
              length=right-left+1;
              maxlen=max(length,maxlen);
        
        hash[s[right]]=right;
        right++;
        }
        
        return maxlen;
    }
};