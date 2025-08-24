class Solution {
public:
    int dis(int n,vector<vector<pair<int,int>>>&graph,int t){
        vector<int>distance(graph.size(),INT_MAX);
        distance[n]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>p;
        p.push({0,n});
        while(p.empty()==false){
            int node=p.top().second;
            int d=p.top().first;
            p.pop();
            for(auto j:graph[node]){
                if(distance[j.second]>distance[node]+j.first){
                    distance[j.second]=distance[node]+j.first;
                     p.push({distance[j.second],j.second});
                }
            }
        }
        vector<int>ans;
        for(auto j:distance){
            
            if(j<=t&&j>0){
                 ans.push_back(j);
            }
        }
        cout<<endl;
        return ans.size();
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][2],edges[i][1]});
             graph[edges[i][1]].push_back({edges[i][2],edges[i][0]});
        }
        int mini=INT_MAX;
        int city=-1;
        for(int i=0;i<n;i++){
            int a=dis(i,graph,distanceThreshold);
            if(mini>=a){
                mini=a;
                city=i;
            }
        }
        return city;
    }
};