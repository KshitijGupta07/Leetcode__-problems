class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<int>degree(n);
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++){
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
                if(degree[i]==1){
                     q.push(i);
                     
                }
        }

        while(n>2){
            int size=q.size();
            n-=size;
            for(int i=0;i<size;i++){
                int front=q.front();
                q.pop();
                for(auto j:graph[front]){
                    degree[j]--;
                    if(degree[j]==1){
                        q.push(j);
                    }
                }
            }
           
           

        }
        vector<int>ans;
        while(q.empty()==false){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;

    }
};