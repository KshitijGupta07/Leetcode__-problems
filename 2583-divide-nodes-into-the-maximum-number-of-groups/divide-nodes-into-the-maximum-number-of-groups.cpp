class Solution {
public:
    bool bipart(vector<int>&color,vector<vector<int>>&graph,int i)
{
     for(auto j:graph[i]){
        if(color[j]==color[i]){
            return false;
        }
        if(color[j]==-1){
            color[j]=(color[i]+1)%2;
                   if(bipart(color,graph,j)==false){
            return false;
        }
        }
       
     }
     return true;
      
}   
   int path(int i,vector<vector<int>>&graph,int n){
         queue<int>q;
         vector<bool>visited(n,false);
         visited[i]=true;
         q.push(i);
         int d=0;
         while(q.size()>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                int front=q.front();
                q.pop();
                for(auto j:graph[front]){
                    if(visited[j]==false){
                        visited[j]=true;
                        q.push(j);
                    }
                }
            }
            d++;
         }
         return d;
   }
   int component(vector<vector<int>>&graph,int i,vector<int>&distance,vector<bool>&visited){
    visited[i]=true;
    int ans=distance[i];
     for(auto j:graph[i]){
        if(visited[j]==false){
            ans=max(ans,component(graph,j,distance,visited));
        }
     }
     return ans;
   }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++){
            
            graph[edges[i][0]-1].push_back(edges[i][1]-1);
            graph[edges[i][1]-1].push_back(edges[i][0]-1);
        }
         vector<bool>visited(n,0);
         vector<int>color(n,-1);
         for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
               if(bipart(color,graph,i)==false){
                return -1;
               }
            }
         }
         vector<int>distance(n,0);
         for(int i=0;i<n;i++){
            distance[i]=path(i,graph,n);
         }
         int ans=0;
         for(int i=0;i<n;i++){
            if(visited[i]==false){
                ans+=component(graph,i,distance,visited);
            }
         }
         return ans;
        
        
        
    }
};