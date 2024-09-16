class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>m;
    
        for(int i=0;i<t.length();i++){
            m[t[i]]++;
        }
        
        int length=INT_MAX;
        int j=0;
        int count=t.length();
        int x=0;
        int y=0;
        while(y<s.length()){
            if(m[s[y]]>0){
                count--;
  
            }
            m[s[y]]--;
            y++;
            if(count==0){
                while(count==0){
                    if(y-x<length){
                        length=y-x;
                        j=x;
                    }
                    m[s[x]]++;
                    if(m[s[x]]>0){
                        count++;
                    }
                    x++;
                }
            }

        }
        if(length==INT_MAX){
            return "";
        }
        return s.substr(j,length);
    }
};