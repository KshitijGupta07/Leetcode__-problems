class Solution {
public:
    string minRemoveToMakeValid(string s) {
        map<int,bool>found;
        string ans="";
        stack<pair<int,char>>e;
        for(int i=0;i<s.length();i++){
            if(e.empty()){
                if(s[i]=='('||s[i]==')'){
                    e.push({i,s[i]});
                }
            }
            else{
               if(e.top().second=='('&&s[i]==')'){
                e.pop();
               }
               else{
                if(s[i]=='('||s[i]==')')
                e.push({i,s[i]});
               }
            }
        }
        while(e.size()>0){
            found[e.top().first]=true;
            cout<<e.top().first<<" "<<e.top().second<<endl;
            e.pop();
        }
        for(int i=0;i<s.length();i++){
            if(found[i]==false){
                ans.push_back(s[i]);
            }
        }
        return ans;



    }
};