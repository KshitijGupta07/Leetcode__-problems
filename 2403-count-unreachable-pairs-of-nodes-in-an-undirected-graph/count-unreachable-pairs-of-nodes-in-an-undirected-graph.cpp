class Solution {
public:
    int bfs(vector<vector<int>>&graph,vector<bool>&visited, int node){
        int count=0;
        visited[node]=true;
        count=1;
        queue<int>q;
        q.push(node);
        while(q.empty()==false){
            int front=q.front();
            q.pop();
            for(auto j:graph[front]){
                if(visited[j]==false){
                    q.push(j);
                    visited[j]=true;
                    count++;
                }
            }
        }
        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n,0);
        vector<int>x;
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                ans= bfs(graph,visited,i);
               x.push_back(ans);
            }
        }
           if(x.size()==1){
            return 0;
           }
           long long a=0;
           vector<long long >prefix;
        for(auto j:x){
            a+=j;
            prefix.push_back(a);
        }
        a=0;
        for(int i=prefix.size()-2;i>=0;i--){
            cout<<prefix[i]<<" "<<x[i+1]<<endl;
            a+=(prefix[i]*x[i+1]);
        }

        return a;
    }
};