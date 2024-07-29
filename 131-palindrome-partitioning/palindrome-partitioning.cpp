class Solution {
public:
  bool isreverse(string s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
  }
    void solve(int index,vector<vector<string>>&ans,vector<string>temp,string s,int n){
        if(index>=n){
            ans.push_back(temp);
        }
        for(int end=index;end<n;end++){
              if(isreverse(s,index,end)==true){
                temp.push_back(s.substr(index,end-index+1));
                solve(end+1,ans,temp,s,s.length());
                 temp.pop_back();
              }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        int n=s.length();
        solve(0,ans,temp,s,n);
        return ans;
    }
};