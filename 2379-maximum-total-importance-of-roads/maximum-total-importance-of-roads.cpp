class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int ,int >edges;
        for(int i=0;i<roads.size();i++){
            edges[roads[i][0]]++;
            edges[roads[i][1]]++;
        }
        vector<pair<long long,long long>>p;
        for(auto j:edges){
            p.push_back({j.second,j.first});
        }
        sort(p.begin(),p.end());
        long long sum=0;
        edges.clear();
        for(int i=p.size()-1;i>=0;i--){
            
            edges[p[i].second]=n;
            n--;
            
        }
        
        for(int i=0;i<roads.size();i++){
            sum+=edges[roads[i][0]]+edges[roads[i][1]];
        }
        
return sum;
    }
};