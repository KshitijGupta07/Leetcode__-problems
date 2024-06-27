class Solution {
public:
void topo(unordered_map<int,vector<int>>&m, unordered_map<int,bool>&visited,int index,stack<int>&s){
    visited[index]=true;
    for(auto j:m[index]){
        if(visited[j]==false){
            topo(m,visited,j,s);
        }
    }
    s.push(index);
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<prerequisites.size();i++){
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        unordered_map<int,bool>visited;
        stack<int>s;
        for(int i=0;i<numCourses;i++){
           if(visited[i]==false){
            topo(m,visited,i,s);
           }
        }
        
        vector<int>ans;
        
        while(s.empty()==false){
            cout<<s.top()<<" ";
            ans.push_back(s.top());
            s.pop();
        }
        map<int,int>mpp;
        for(int i=0;i<ans.size();i++){
            mpp[ans[i]]=i;
        }
        for(auto j:m){
            for(auto k:j.second){
                if(mpp[k]<=mpp[j.first]){
                    return false;
                }
            }
        }
        
        return true;
    }
};