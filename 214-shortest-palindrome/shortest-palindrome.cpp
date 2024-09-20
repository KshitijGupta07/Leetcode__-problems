class Solution {
public:
  vector<int>lps(string total){
      int i=1;
      int length=0;
      vector<int>p(total.length(),0);
         for(int i=1;i<total.length();i++){
            while(length>0&& total[i]!=total[length]){
                length=p[length-1];
            }
            if(total[i]==total[length]){
                length++;
            }
            p[i]=length;
         }
      return p;
  }
    string shortestPalindrome(string s) {
        string k=s;
        reverse(k.begin(),k.end());
        string total=s+"#"+k;
        vector<int>p=lps(total);
        int l=p[p.size()-1];
        cout<<l<<endl;
        string lo=s.substr(l);
        reverse(lo.begin(),lo.end());
          return lo+s;
        
    
    }
};