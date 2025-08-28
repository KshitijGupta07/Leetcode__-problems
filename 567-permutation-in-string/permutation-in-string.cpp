class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return 0;
        }
        string ans="";
        for(int i=0;i<s1.length();i++){
                ans.push_back(s2[i]);
        }
        map<string,bool>m;
        m[ans]=true;
        for(int i=s1.length();i<s2.length();i++){
            ans.erase(ans.begin());
            ans.push_back(s2[i]);
            m[ans]=true;
        }
        string t=s1;
        sort(t.begin(),t.end());
        for(auto j:m){
            string x=j.first;
             sort(x.begin(),x.end());
           if(x==t){
            return true;
           }
        }
        return false;
    }
};