class Solution {
public:
     void dfs(vector<vector<int>>&graph,int i,unordered_map<int ,bool>&visited){
      visited[i]=true;
      for(auto j:graph[i]){
          if(visited[j]==false){
            dfs(graph,j,visited);
          }
      }
   }
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<int>outdegree(n);
        vector<int>indegree(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            outdegree[edges[i][0]];
            indegree[edges[i][1]];
        }
        bool s=false;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                 unordered_map<int,bool>visited;
                 dfs(graph,i,visited);
                 if(visited.size()==n){
                    s=true;
                    visited.clear();
                    return i;
                 }
            }
        }
        
            return -1;
        

    }
};