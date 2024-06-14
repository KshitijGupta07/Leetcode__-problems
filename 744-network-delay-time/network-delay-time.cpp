class Solution {
public:
// void dfs(int node, unordered_map<int,bool>&visited,unordered_map<int,vector<pair<int,int>>>&mpp,stack<int>&st){
//     visited[node]=true;
//      for(auto neighbour:mpp[node]){
//          if(visited[neighbour.first]!=true){
    
//                   dfs(neighbour.first,visited,mpp,st);
//         }
//     }
//     st.push(node);
//  }
// void dist(int& source,unordered_map<int,bool>&visited,unordered_map<int,vector<pair<int,int>>>&mpp,vector<int>&distance,stack<int>&st){
//     distance[source]=0;
//     visited[source]=true;
//     while(st.empty()==false){
//         int top=st.top();
//         st.pop();
//         if(top!=INT_MAX){
            
//             for(auto j:mpp[top]){
//                 if(distance[top]+j.second<=distance[j.first]){
//                     distance[j.first]=distance[top]+j.second;
//                 }
//             }
//         }
//     }
    

// }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>mpp;
        for(int i=0;i<times.size();i++){
            int firstnode=times[i][0];
            int secondnode=times[i][1];
            int edge=times[i][2];
            mpp[firstnode].push_back(make_pair(secondnode,edge));
        }
        
        unordered_map<int,bool>visited;
    
         
        vector<int>distance(n+1,INT_MAX);
        int node=k;
        distance[node]=0;
       priority_queue<pair<int,int>>p;
       p.push({0,node});
       while(p.empty()==false){
          pair<int,int>top=p.top();
          p.pop();
          for(auto j:mpp[top.second]){
             if(distance[j.first]>distance[top.second]+j.second){
                distance[j.first]=distance[top.second]+j.second;
                p.push({distance[j.first],j.first});
             }
          }
       }
       int max=INT_MIN;
       for(int i=1;i<n+1;i++){
        if(max<distance[i]){
           max=distance[i];
        }
       }
       if(max==INT_MAX){
        return -1;
       }
       return max;
    }
};