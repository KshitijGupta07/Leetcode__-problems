class Solution {
public:
   bool check(string a){
    int start=0;
    int end=a.length()-1;
    while(start<=end){
        if(a[start]!=a[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
   }
   void solve(string s,int i,vector<string>&temp,vector<vector<string>>&ans){
      if(i>=s.length()){
        ans.push_back(temp);
      }
      for(int x=i;x<s.length();x++){
            string t=s.substr(i,x-i+1);
            if(check(t)){
                temp.push_back(t);
                solve(s,x+1,temp,ans);
                temp.pop_back();
            }
      }
   }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(s,0,temp,ans);
        return ans;
    }
};