class Solution {
public:
   bool check(int i,vector<bool>&visited,vector<bool>&color,vector<vector<int>>&graph){
       visited[i]=true;
       queue<int>q;
       q.push(i);
       color[i]=0;
       while(q.empty()==false){
           int front=q.front();
           q.pop();
           for(auto j:graph[front]){
             if(visited[j]==false){
                visited[j]=true;
                q.push(j);
                color[j]=1-color[front];
             }
             else{
                if(color[j]==color[front]){
                    return false;
                }
             }
           }
       }
       return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>color(n,0);
        vector<bool>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(check(i,visited,color,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};