class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>m1;
        map<string,int>m2;
        vector<string>ans;
        string a="";
        for(int i=0;i<s1.length();i++){
              if(s1[i]==' '){
                m1[a]++;
                a.clear();
              }
              else{
                a.push_back(s1[i]);
              }
        }
        m1[a]++;
        a="";
            for(int i=0;i<s2.length();i++){
              if(s2[i]==' '){
                m2[a]++;
                a.clear();
              }
              else{
                a.push_back(s2[i]);
              }
        }
        m2[a]++;

        for(auto j:m1){
            if(m2[j.first]==0&&j.second==1){
                ans.push_back(j.first);
            }
        }
        for(auto j:m2){
            if(m1[j.first]==0&&j.second==1){
                ans.push_back(j.first);
            }
        }
        return ans;

    }
};