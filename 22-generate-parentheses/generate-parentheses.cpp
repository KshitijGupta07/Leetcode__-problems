class Solution {
public:
   bool check(string s){
    string x="";
      for(auto j:s){
        if(x.empty()){
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
   void generate(vector<string>&ans,int n,string temp){
       if(temp.length()==2*n){
        
           if(check(temp)){
            cout<<temp<<endl;
            ans.push_back(temp);
            return;
            
           }
           else{
           return;
           }
       }
       temp.push_back('(');
       generate(ans,n,temp);
       temp.pop_back();
       temp.push_back(')');
       generate(ans,n,temp);

   }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int count=1;
        generate(ans,n,"");
        return ans;
    }
};