class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dis(n,INT_MAX);
        dis[k-1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>p;
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<times.size();i++){
            graph[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        p.push({0,k-1});
        
        while(p.empty()==false){
            pair<int,int>top=p.top();
            p.pop();
            for(auto j:graph[top.second]){
                if(dis[j.first]>top.first+j.second){
                    dis[j.first]=top.first+j.second;
                    p.push({dis[j.first],j.first});
                }
            }
        }
        int maxi=0;
        for(auto j:dis){
        maxi=max(maxi,j);
        }
        if(maxi==INT_MAX){
            return -1;
        }
        return maxi;
    }
};