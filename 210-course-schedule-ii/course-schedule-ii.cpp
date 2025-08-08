class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>topo;
        vector<int>indegree(numCourses);
        vector<vector<int>>graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
                indegree[prerequisites[i][1]]++;
                graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                 q.push(i);
            }
        }
        while(q.empty()==false){
            int front=q.front();
            q.pop();
            topo.push_back(front);
            for(auto j:graph[front]){
                indegree[j]-=1;
                if(indegree[j]==0){
                    q.push(j);
                }
            }
        }
        reverse(topo.begin(),topo.end());
        if(topo.size()!=numCourses){
            return {};
        }
        return topo;
    }
};