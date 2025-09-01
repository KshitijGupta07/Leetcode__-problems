class Solution {
public:
static bool comparator(pair<int,string>&A,pair<int,string>&B){
    if(A.first==B.first){
        return A.second<=B.second;
    }
    return A.first>B.first;
}
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int,string>>v;
        map<string,int>m;
        for(auto j:words){
            m[j]+=1;
        }
        for(auto j:m){
            v.push_back({j.second,j.first});
        }
        vector<string>ans;
        
        sort(v.begin(),v.end(),comparator);
       for(auto j:v){
        if(k>0){
            ans.push_back(j.second);
        }
        k-=1;
       }
        return ans;
    }
};