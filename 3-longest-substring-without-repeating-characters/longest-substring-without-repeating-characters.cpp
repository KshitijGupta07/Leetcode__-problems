class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,0);
        int l=0;
        int r=0;
        int ans=0;
        if(s.length()==0){
            return 0;
        }
        if(s.length()==1){
            return 1;
        }
        while(r<s.length()){
            if(hash[s[r]]==0){
                hash[s[r]]=1;
                r++;
            }
            else{
                
                if(hash[s[l]]==1){
                    hash[s[l]]=0;
                    l++;
                    
                    ans=max(ans,r-l+1);
                }
            }
        }
        r=s.length()-1;
        cout<<l<<" "<<r<<endl;
        return max(ans,r-l+1);
    }
};