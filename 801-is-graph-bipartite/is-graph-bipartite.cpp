class Solution {
public:
   bool solve(vector<vector<int>>&graph,int i, vector<int>&color,vector<bool>&visited){
       visited[i]=true;
       for(auto j:graph[i]){
        if(visited[j]==false){
            color[j]=1-color[i];
            if(solve(graph,j,color,visited)==false){
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
        vector<int>color(graph.size(),-1);
        color[0]=0;
        vector<bool>visited(graph.size(),false);
        
        for(int i=0;i<graph.size();i++){
            bool ans=solve(graph,i,color,visited);
            if(ans==false){
                return false;
            }
        }
        return true;
    }
};