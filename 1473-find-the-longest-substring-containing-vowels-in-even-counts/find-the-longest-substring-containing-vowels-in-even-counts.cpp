class Solution {
public:
    int findTheLongestSubstring(string s) {
         vector<int>c(26,0);
         if(s.length()==1){
            return 0;
         }
         c['a'-'a']=1;
         c['e'-'a']=2;
         c['i'-'a']=4;
         c['o'-'a']=8;
         c['u'-'a']=16;
        vector<int>v(32,-1);
        int a=0;

        int ans=INT_MIN;
        for(int i=0;i<s.length();i++){
            
            a^=c[s[i]-'a'];
        
            if(v[a]==-1&&a!=0){
                v[a]=i;
            }
            else{
            
           ans=max(ans,i-v[a]);
            }
        }
        
        
        return ans;
    }
};