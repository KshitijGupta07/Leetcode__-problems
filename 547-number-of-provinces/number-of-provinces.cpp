class Solution {
public:
   void dfs(int i,vector<vector<int>>&graph,unordered_map<int,bool>&visit){
     visit[i]=true;
     for(auto j:graph[i]){
        if(visit[j]==false){
            dfs(j,graph,visit);
        }
     }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int m=isConnected.size();
        int n=isConnected[0].size();
        vector<vector<int>>graph(n+1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&isConnected[i][j]==1){
                   graph[i+1].push_back(j+1);
                }
            }
        }
        unordered_map<int,bool>visit;
        int count=0;
        for(int i=1;i<=n;i++){
            if(visit[i]==false){
                dfs(i,graph,visit);
                count+=1;
            }
        }
        return count;
    }
};