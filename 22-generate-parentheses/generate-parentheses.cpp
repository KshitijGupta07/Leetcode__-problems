class Solution {
public:
   bool check(string ans){
      stack<char>st;
      for(int i=0;i<ans.length();i++){
           if(st.empty()){
            st.push(ans[i]);
           }
           else{
            if(st.top()=='('&&ans[i]==')'){
                st.pop();
            }
            else{
                st.push(ans[i]);
            }
           }
      }
      return  st.empty();
   }
    void solve(int n ,string ans,vector<string>&m){
        if(n<=0){
            m.push_back(ans);
            return;
        }
        ans.push_back('(');
        solve(n-1,ans,m);
        ans.pop_back();
        ans.push_back(')');
        solve(n-1,ans,m);
        

    }
    vector<string> generateParenthesis(int n) {
        vector<string>m;
        vector<string>ans;
        solve(2*n,"",m);
        for(auto j:m){
            if(check(j)){
               ans.push_back(j);
            }
        }
        return ans;
    }
};