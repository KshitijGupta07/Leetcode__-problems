class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash1(256,0);
        for(int i=0;i<t.length();i++){
            hash1[t[i]-'0']+=1;
        }
        int count=t.length();
        int l=0;
        int r=0;
        int start=-1;
        int end=-1;
        int length=INT_MAX;
        while(r<s.length()){
            if(hash1[s[r]-'0']>0){
                count-=1;
            }
            hash1[s[r]-'0']-=1;
            while(count==0){
                if(length>r-l+1){
                    length=r-l+1;
                    start=l;
                    end=r;
                }
                hash1[s[l]-'0']+=1;
                
                if(hash1[s[l]-'0']>0){
                    count++;
                }
                l++;
            }
            r++;
        }
        if(start==-1){
            return "";
        }
        return s.substr(start,end-start+1);

    }
};