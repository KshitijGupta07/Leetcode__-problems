class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<pair<int,int>>q;
    
        
        vector<int>color(graph.size(),-1);
    
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
         q.push({i,0});
         color[i]=0;
        while(q.empty()==false){
          pair<int,int>front=q.front();
           q.pop();
           for(auto j:graph[front.first]){
            if(color[j]==-1){
                color[j]=1-front.second;
                q.push({j,color[j]});
            }
            else{
                if(color[j]==color[front.first]){
                    return false;
                }
            }
           }
        }
            }
        }

        return true;
    }
};