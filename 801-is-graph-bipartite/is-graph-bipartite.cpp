class Solution {
public:
    bool check(int i,vector<bool>&visited,vector<vector<int>>&graph,vector<int>&color){
         visited[i]=true;
         
         for(auto j:graph[i]){
             if(visited[j]==false){
                
                color[j]=1-color[i];
                if(check(j,visited,graph,color)==false){
                    return false;
                }
             }
             else{
                if(color[j]==color[i]){
                    return false;
                }
            
             }
         }
         return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>visited(n,false);
        vector<int>color(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(check(i,visited,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};