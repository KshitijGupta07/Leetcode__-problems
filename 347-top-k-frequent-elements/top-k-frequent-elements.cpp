class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto j:nums){
            m[j]+=1;
        }
        vector<int>ans;
        priority_queue<pair<int,int>>p;
        for(auto j:m){
            p.push({j.second,j.first});
        }
        while(k>0){
            ans.push_back(p.top().second);
            p.pop();
            k-=1;
        }
        return ans;

    }
};