class Solution {
public:
void removepart(string &s,string &part,int pos){
    
    if(pos<0){
        return;
    }
    s.erase(pos,part.length());
    pos=s.find(part);
    removepart(s,part, pos);
}
    string removeOccurrences(string s, string part) {
        removepart(s,part,s.find(part));
        return s;
    }
};