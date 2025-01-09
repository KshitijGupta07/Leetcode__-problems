class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
       map<long long ,long long >m;
       for(int i=0;i<segments.size();i++){
        m[segments[i][0]]+=segments[i][2];
        m[segments[i][1]]-=segments[i][2];
       } 
     
       vector<pair<long long,long long >>v;
       vector<vector<long long>>ans;
         for(auto j:m){
        v.push_back({j.first,j.second});
       }
       long long sum=0;
       for(int i=0;i<v.size();i++){
          sum+=v[i].second;
          v[i].second=sum;
       }
       for(int i=0;i<v.size()-1;i++){
        if(v[i].second!=0)
          ans.push_back({v[i].first,v[i+1].first,v[i].second});
       }
       return ans;

    }
};