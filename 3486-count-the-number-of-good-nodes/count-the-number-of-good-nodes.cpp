class Solution {
public:
int count=0;
   int dfs(vector<vector<int>>&adj,int index,int parent){
    
       unordered_set<int>sub;
       int subsize=1;
       for(auto j:adj[index]){
        if(j==parent){
            continue;
        }
          int currsubsize=dfs(adj,j,index);
          subsize+=currsubsize;
            sub.insert(currsubsize);
       }
       if(sub.size()<=1){
        count=count+1;
       }
       return subsize;
   }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int a=dfs(adj,0,-1);
        return count;
    }
};