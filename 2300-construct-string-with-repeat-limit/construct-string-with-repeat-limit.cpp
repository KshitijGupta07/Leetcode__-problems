class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>hash(26,0);
        for(auto j:s){
            hash[j-'a']++;
        }
        priority_queue<pair<char,int>>p;
        for(int i=0;i<hash.size();i++){
            if(hash[i]>0){
                p.push({i+'a',hash[i]});
            }
        }
        string ans="";
        while(p.empty()==false){
          pair<char,int>top=p.top();
          p.pop();
           char c=top.first;
           int f=top.second;
           int count=repeatLimit;
           while(count>0&&f>0){
             ans.push_back(c);
             count--;
             f--;
           }  
           if(f>0){
             if(p.empty()==false){
                pair<char,int>top2=p.top();
                p.pop();
                char ch=top2.first;
                 ans.push_back(ch);
                 int f2=top2.second;
                 f2=f2-1;
                 if(f2>0){
                    p.push({ch,f2});
                 }


             }
             else{
                break;
             }
             p.push({c,f});
           }
        }
        return ans;
    }
};