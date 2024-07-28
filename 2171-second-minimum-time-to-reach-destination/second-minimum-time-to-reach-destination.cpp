class Solution {
public:
   int dijkistra(vector<vector<int>>&graph,int n){
      vector<int>distance(n+1,INT_MAX);
      vector<int>distance2(n+1,INT_MAX);
      unordered_map<int,bool>visited;
      distance[1]=0;
      int a=n;
        queue<pair<int,int>>q;
        q.push({1,0});
         while(q.empty()==false){
              int top=q.front().first;
              int dis=q.front().second;
              q.pop();
              for(auto j:graph[top]){
                
                int newd=dis+1;
                                if(distance[j]>newd){
                    distance2[j]=distance[j];
                    distance[j]=newd;
                    q.push({j,newd});
                }
                else if(distance[j]<newd&&distance2[j]>newd){
                    distance2[j]=newd;
                    q.push({j,newd});

                }
              }
            }
         
   return distance2[n];
   }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
         vector<vector<int>>graph(n+1);
        
         for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
         }
        
          
        int a=dijkistra(graph,n); 
        int totaltime=0;
        int x=0;
        for(int i=1;i<=a;i++){
           
           int a=x/change;
           if(a%2==1){
             x=(a+1)*change;
           }
           x+=time;
        }
    
        
        return x;
    }
};