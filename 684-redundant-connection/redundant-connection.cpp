class Solution {
public:
    void dfs(int &cycle,vector<vector<int>>& graph,vector<int>&parent,vector<bool>&visited,int node){
        visited[node]=true;
        for(auto j:graph[node]){
            if(visited[j]==false){
                parent[j]=node;
                dfs(cycle,graph,parent,visited,j);
                
            }
            else{
                if(parent[node]!=j&&cycle==-1){
                    cycle=j;
                    parent[j]=node;
                }
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>>graph(edges.size());
         vector<int>parent(edges.size(),-1);
         for(int i=0;i<edges.size();i++){
            graph[edges[i][0]-1].push_back(edges[i][1]-1);
             graph[edges[i][1]-1].push_back(edges[i][0]-1);
         }
         int cycle=-1;
         vector<bool>visited(edges.size(),false);
          map<int,int>m;
         dfs(cycle,graph,parent,visited,0);
         int node=cycle;
         do{
            m[node]=1;
            cout<<node<<endl;
            node=parent[node];
         }while(node!=cycle);
         vector<int>ans;
         for(int i=edges.size()-1;i>=0;i--){
             if(m[edges[i][0]-1]&&m[edges[i][1]-1]){
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                return ans;
             }
         }
         return ans;

    }
};