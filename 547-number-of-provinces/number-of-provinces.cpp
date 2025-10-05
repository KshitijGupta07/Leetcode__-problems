class Solution {
public:
   void dfs(int node,vector<bool>&visited,vector<vector<int>>&graph){
    visited[node]=true;
    for(auto j:graph[node]){
        if(visited[j]==false){
            dfs(j,visited,graph);
        }
    }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                 if(isConnected[i][j]==1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                 }
            }
        }
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(i,visited,graph);
                count++;
            }
        }
        return count;
    }
};