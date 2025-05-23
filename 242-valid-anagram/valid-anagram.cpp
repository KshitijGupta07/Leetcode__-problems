class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>m;
        
        for(auto j:s){
            m[j]++;
        }
        map<char,int>x;
        for(auto j:t){
            x[j]++;
        }
        if(m.size()!=x.size()){
            return false;
        }
        for(auto j:x){
            if(m[j.first]==j.second){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};