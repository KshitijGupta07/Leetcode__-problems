class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>distance(n,0);
        vector<int>ans;
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(i);
        }
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            x=x+1;
            
            auto lb=s.lower_bound(x);
            auto ub=s.lower_bound(y);
            s.erase(lb,ub);
            ans.push_back(s.size()-1);
        }
        return ans;
    }
};