class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
          vector<vector<int>>list(n);
          vector<int>indegree(n);
          for(int i=0;i<edges.size();i++){
            list[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
          }
          queue<int>q;
          for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
          }
          vector<unordered_set<int>>ans(n);
          while(q.size()!=0){
            int top=q.front();
        q.pop();
            for(int v:list[top]){
                indegree[v]--;
                ans[v].insert(top);
                for(int i:ans[top]){
                    ans[v].insert(i);
                }
                if(indegree[v]==0){
                    q.push(v);
                }
            }
          }
          vector<vector<int>>a(n);
          for(int i=0;i<n;i++){
            a[i]=vector<int>(ans[i].begin(),ans[i].end());
            sort(a[i].begin(),a[i].end());
          }
          return a;
          
    }
};