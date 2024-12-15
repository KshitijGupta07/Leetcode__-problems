class Solution {
public:
    void bfs(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1,map<string,double>&dis,map<string,vector<pair<string,double>>>&m){
        map<string,bool>found;
        queue<string>q;
        q.push(initialCurrency);
        found[initialCurrency]=true;
         while(q.empty()==false){
            string f=q.front();
            q.pop();
            for(auto j:m[f]){
                if(found[j.first]==false){
                    if(dis[j.first]==0.00){
                        dis[j.first]=1.00;
                        dis[j.first]*=(dis[f]*j.second);
                    }
                    else{
                        dis[j.first]=max(dis[j.first],dis[f]*j.second);
                    }
                    found[j.first]=true;
                    q.push(j.first);
                }
            }

         }
         found.clear();

    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        map<string,vector<pair<string,double>>>m;
        map<string,vector<pair<string,double>>>m2;

        for(int i=0;i<pairs1.size();i++){
            m[pairs1[i][0]].push_back({pairs1[i][1],rates1[i]});
            m[pairs1[i][1]].push_back({pairs1[i][0],1.00/rates1[i]});
        }
        for(int i=0;i<pairs2.size();i++){
            m2[pairs2[i][0]].push_back({pairs2[i][1],rates2[i]});
            m2[pairs2[i][1]].push_back({pairs2[i][0],1.00/rates2[i]});
        }
       
        map<string,double>dis;
        map<string,double>dis2;
    
        dis[initialCurrency]=1.00;
        bfs(initialCurrency,pairs1,rates1,dis,m);

       double ans=1.00;
        for(auto j:dis){
            if(j.first!=initialCurrency){
                dis2[j.first]=1.000;
            bfs(j.first,pairs2,rates2,dis2,m2);
            ans=max(ans,dis2[initialCurrency]*dis[j.first]);
            }
            

            dis2.clear();
        }
    
    
        return ans;
    }
};