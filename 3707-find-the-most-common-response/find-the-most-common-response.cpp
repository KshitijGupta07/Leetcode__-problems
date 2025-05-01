class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string,int>ans;
        for(int i=0;i<responses.size();i++){
            map<string,int>m;
            for(int j=0;j<responses[i].size();j++){
                  m[responses[i][j]]++;
            }
            for(auto j:m){
                 ans[j.first]++;
            }
            m.clear();
        }
        int maxi=INT_MIN;
        for(auto j:ans){

              maxi=max(maxi,j.second);
        }
        for(auto j:ans){
            if(j.second==maxi){
                return j.first;
            }
        }
        return "";
    }
};