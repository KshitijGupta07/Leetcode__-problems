class Solution {
public:
   bool check(string s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
   }
   void solve(vector<vector<string>>&ans,vector<string>temp,string s,int i){
    if(i==s.length()){
        ans.push_back(temp);
        return;
    }
    string t="";
       for(int index=i;index<s.length();index++){
          t.push_back(s[index]);
           if(check(s,i,index)){
              temp.push_back(t);
              
              solve(ans,temp,s,index+1);
              temp.pop_back();
           }
       }
   }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        int i=0;
        solve(ans,temp,s,i);
        return ans;
    }
};