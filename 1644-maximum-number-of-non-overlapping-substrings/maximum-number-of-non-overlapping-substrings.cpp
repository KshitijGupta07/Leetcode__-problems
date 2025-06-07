class Solution {
public:
   int valid(int i,string s,vector<pair<int,int>>&v){
       int right=v[s[i]-'a'].second;
       for(int x=i;x<v[s[i]-'a'].second;x++){
           if(v[s[x]-'a'].first<i){
            return -1;
           }
           right=max(right,v[s[x]-'a'].second);
       }
       return right;
   }
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int,int>>v(26,{-1,-1});
        
        for(int i=0;i<s.length();i++){
            if(v[s[i]-'a'].first==-1){
                v[s[i]-'a'].first=i;
            }
        }
        for(int i=s.length()-1;i>=0;i--){
            if(v[s[i]-'a'].second==-1){
                v[s[i]-'a'].second=i;
            }
        }
         vector<pair<int,int>>t;
         for(int i=0;i<26;i++){
            if(v[i].first!=-1){
                int a=v[i].first;
                int b=v[i].second;
                for(int j=a;j<=b;j++){
                    a=min(a,v[s[j]-'a'].first);
                    b=max(b,v[s[j]-'a'].second);
                }
                if(a==v[i].first){
                    t.push_back({a,b});
                }
            }
         }
         for(auto j:t){
            cout<<j.first<<" "<<j.second<<endl;
         }
         sort(t.begin(),t.end());
         vector<pair<int,int>>t2;
         for(int i=0;i<t.size();i++){
            if(t2.empty()==true){
                t2.push_back(t[i]);
            }
            else{
                if(t2.back().second>t[i].first){
                    int a=max(t2.back().first,t[i].first);
                    int b=min(t2.back().second,t[i].second);
                    t2.pop_back();
                    t2.push_back({a,b});
                }
                else{
                    t2.push_back(t[i]);
                }
            }
         }
         vector<string>ans;
         for(auto j:t2){
                ans.push_back(s.substr(j.first,j.second-j.first+1));
            cout<<j.first<<" "<<j.second<<endl;
         }
         return ans;
    }
};