class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int,int>m;
        map<int,vector<int>>mp;
        map<int,vector<int>>mpi;
        int ans=0;
        sort(buildings.begin(),buildings.end());
        for(int i=0;i<buildings.size();i++){
            m[buildings[i][1]]++;
            mp[buildings[i][1]]=buildings[i];
        }
        for(int i=buildings.size()-1;i>=0;i--){
            mpi[buildings[i][1]]=buildings[i];
        }
        for(int i=1;i<buildings.size()-1;i++){
            if(buildings[i][0]==buildings[i-1][0]&&buildings[i][0]==buildings[i+1][0]){
                cout<<m[buildings[i][1]]<<endl;
                  if(m[buildings[i][1]]>2&&mp[buildings[i][1]]!=buildings[i]&&mpi[buildings[i][1]]!=buildings[i]){
                    ans++;
                  }
            }
        }
        return ans;
    }
};