class Solution {
public:
   double bfs(vector<vector<string>>&equations,vector<double>&values,string s,string e,map<string,vector<pair<string,double>>>&m){
       queue<string>eq;
       map<string,bool>visited;
       map<string,double>dis;
       dis[s]=1.00;
        
       eq.push(s);
       visited[s]=true;
       double d=1.00;
       while(eq.empty()==false){
          string f=eq.front();
          eq.pop();
          for(auto j :m[f]){
            if(visited[j.first]==false){
                visited[j.first]=true;
                eq.push(j.first);
                   if(dis[j.first]==0){
                    dis[j.first]=1.00;
                dis[j.first]*=(dis[f]*(j.second));
                   }
                   else{
                     dis[j.first]*=(dis[f]*(j.second));
                   }
                
            }
          }

       }
       return dis[e];

   }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>>m;
        map<string,bool>found;
        vector<double>ans;
        for(int i=0;i<equations.size();i++){
            string a=equations[i][0];
            string b=equations[i][1];
            m[a].push_back({b,values[i]});
            m[b].push_back({a,1.0/values[i]});
            found[a]=true;
            found[b]=true;
        }
        for(int i=0;i<queries.size();i++){
            if(found[queries[i][0]]==false||found[queries[i][1]]==false){
                ans.push_back(-1);
            }
            else{
            double x=bfs(equations,values,queries[i][0],queries[i][1],m);
            if(x==0){
                x=-1;
            }
            ans.push_back(x);
            }
        }
        return ans;
    }
};