class Solution {
public:
   void dfs(vector<vector<int>>&graph,vector<bool>&visited,int i){
    visited[i]=true;
    for(auto j:graph[i]){
        if(visited[j]==false){
            dfs(graph,visited,j);
        }
    }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>graph(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int n=isConnected.size();
        int count=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(graph,visited,i);
                count++;
            }
        }
        return count;
    }
};