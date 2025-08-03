class Solution {
public:
   void solve(string &digits,map<int,string>&m,vector<string>&ans,int i,string temp){
      if(i>=digits.length()){
        ans.push_back(temp);
        return;
      }
      string x=m[digits[i]-'0'];
      for(int index=0;index<x.length();index++){
           temp.push_back(x[index]);
           solve(digits,m,ans,i+1,temp);
           temp.pop_back();
      }
   }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        map<int,string>m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        vector<string>ans;
        solve(digits,m,ans,0,"");
        return ans;
    }
};