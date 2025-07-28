class Solution {
public: 
   bool check(string s){
    int start=0;
    int end=s.length()-1;
      while(start<=end){
        if(s[start]!=s[end]){
              return false;
        }
        start++;
        end--;
      }
      return true;
   }
    void solve(string s,vector<string>temp,vector<vector<string>>&ans,int i){
        if(i>=s.length()){
            ans.push_back(temp);
            return;
        }
        string t="";
        for(int index=i;index<s.length();index++){
            t.push_back(s[index]);
            if(check(t)){
                temp.push_back(t);
                solve(s,temp,ans,index+1);
                temp.pop_back();
            }
            

        }

    }
    vector<vector<string>> partition(string s) {
        int i=0;
        vector<string>temp;
        vector<vector<string>>ans;
        solve(s,temp,ans,i);
        return ans;
    }
};