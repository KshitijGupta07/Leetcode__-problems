class Solution {
public:
   void bfs(vector<vector<int>>&reach,vector<vector<int>>&graph,int node,int n){
      queue<int>q;
       q.push(node);
       vector<bool>visited(n,false);
       visited[node]=true;
       while(q.empty()==false){
           int front=q.front();
           q.pop();
           for(auto j:graph[front]){
                if(visited[j]==false){
                    visited[j]=true;
                    reach[node][j]=true;
                    q.push(j);
                }
           }
       }
   }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>graph(numCourses);
        
        vector<vector<int>>reach(numCourses,vector<int>(numCourses,0));
         map<int,bool>found;
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            found[a]=true;
            found[b]=true;
            graph[a].push_back(b);
    
        }
        vector<bool>ans;
        for(int i=0;i<numCourses;i++){
            bfs(reach,graph,i,numCourses);
        }
        for(int i=0;i<reach.size();i++){
            for(int j=0;j<reach[0].size();j++){
                cout<<reach[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0];
            int b=queries[i][1];
            if(reach[a][b]==true){
                 ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
       
   return ans;
        
       
    }
};