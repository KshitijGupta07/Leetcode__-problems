class Solution {
public:
   bool check(string& temp){
      string x="";
      for(auto j:temp){
        if(x.empty()==true){
            x.push_back(j);
        }
        else{
            if(x.back()=='('&&j==')'){
            x.pop_back();
            }
            else{
                x.push_back(j);
            }
        }
      }
      return x.empty();
   }
    void solve(int n,int i,vector<string>&ans,string temp){
        if(i>=2*n){
        
            if(check(temp)){
           ans.push_back(temp);
            }

           return;
        }
        temp.push_back('(');
        solve(n,i+1,ans,temp);
        temp.pop_back();
        temp.push_back(')');
        solve(n,i+1,ans,temp);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,0,ans,"");
        return ans;
    }
};