class Solution {
public:
  void dfs(vector<int>&ans,unordered_map<int,deque<int>>&graph,int &node){

    while(graph[node].empty()==false){
          int j=graph[node].front();
          graph[node].pop_front();
    
            
             dfs(ans,graph,j);
           
      }
     
      ans.push_back(node);
  }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,deque<int>>graph;
        unordered_map<int,int>indegree;
        unordered_map<int,int>outdegree;
        for(int i=0;i<pairs.size();i++){
            graph[pairs[i][0]].push_back(pairs[i][1]);
            indegree[pairs[i][1]]++;
            outdegree[pairs[i][0]]++;
        }
       int node=-1;
       unordered_map<int,bool>visited;
        for(auto j:outdegree){
            if(indegree[j.first]+1==outdegree[j.first]){
                node=j.first;
                break;
            }
        }
       
        if(node==-1){
            node=pairs[0][0];
        }
         
        vector<int>ans;
       
        dfs(ans,graph,node);
        reverse(ans.begin(),ans.end());
       vector<vector<int>>valid;
       for(int i=0;i<ans.size()-1;i++){
        valid.push_back({ans[i],ans[i+1]});
       }
        
        return valid;

    }
};