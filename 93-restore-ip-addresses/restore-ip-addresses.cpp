class Solution {
public:
  bool check(string &s){
     if(s.length()>1&&s[0]=='0'){
        return false;
     }
    if(s.length()==1&&s[0]=='0'){
        return true;
    }
     if(s.length()>3){
        return false;
     }
      long long num=0;
      for(int i=0;i<s.length();i++){
        num=num*10+(s[i]-'0');
      }
      
      if(num>255){
        return false;
      }
      return true;
  }
   void solve(vector<string>&ans,vector<string>sub,string &s,int index,int end,int count){
      if(count==3){
        string a=s.substr(index);
        string f="";
        if(a.length()>0&&check(a)==true){
            sub.push_back(a);
            for(auto j:sub){
                f+=j;
            }
        }
        if(f.size()>0){
        ans.push_back(f);
        }
        cout<<endl;
        return;
      }
         for(int i=index;i<end;i++){
            string a="";
             a=s.substr(index,i-index+1);
            if(check(a)==true){
            
               
                a.push_back('.');
                
                sub.push_back(a);
                count=count+1;
                solve(ans,sub,s,i+1,end,count);
                 count=count-1;
                 
                 sub.pop_back();

            }
         }
         
   }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        int index=0;
        int end=s.length();
        int count=0;
        vector<string>sub;
        solve(ans,sub,s,index,end,count);
           return ans;
    }
};