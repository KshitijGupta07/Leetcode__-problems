class Solution {
public:
   vector<int>kmp(string s){
     vector<int>ans(s.length(),0);
     int l=0;
     for(int i=1;i<s.length();){
         if(s[l]==s[i]){
             l++;
             ans[i]=l;
             i++;
         }
         else if(l>0){
            l=ans[l-1];
         }
         else{
            i++;
         }
         
     }
     return ans;

   }
    string longestPrefix(string s) {
        vector<int>pr=kmp( s);

        string ans="";
        for(int i=0;i<pr.back();i++){
            ans.push_back(s[i]);
        }
        return ans;
    }
};