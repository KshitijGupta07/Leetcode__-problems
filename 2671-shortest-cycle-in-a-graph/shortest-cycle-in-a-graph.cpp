class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>v(n);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            
            vector<int>parent(n,-1);
            vector<int>dist(n,100000);
            dist[i]=0;
            queue<int>q;
            q.push(i);
            
            while(q.empty()==false){
                int front=q.front();
                q.pop();
                for(auto child:v[front]){
                    if(dist[child]==100000){
                        dist[child]=dist[front]+1;
                        parent[child]=front;
                        q.push(child);
                    }
                    else if(parent[child]!=front&&parent[front]!=child){
                         ans=min(ans,dist[front]+dist[child]+1);
                    }
                }
            }

            }
            if(ans==INT_MAX){
                return -1;
            }
            return ans;
        
    }
};