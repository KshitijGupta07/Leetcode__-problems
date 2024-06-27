class Solution {
public:
void topo(unordered_map<int,vector<int>>&m, unordered_map<int,bool>&visited,int index,vector<int>&ans){
    visited[index]=true;
    for(auto j:m[index]){
        if(visited[j]==false){
            topo(m,visited,j,ans);
        }
    }
    ans.push_back(index);
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<prerequisites.size();i++){
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        unordered_map<int,bool>visited;
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
           if(visited[i]==false){
            topo(m,visited,i,ans);
           }
        }
        

        
        reverse(ans.begin(),ans.end());
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