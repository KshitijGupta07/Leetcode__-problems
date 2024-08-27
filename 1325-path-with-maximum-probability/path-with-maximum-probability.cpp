class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>probability(n,0.00);
        probability[start_node]=1.00;
        for(int i=0;i<n-1;i++){
            bool f=false;
            for(int j=0;j<edges.size();j++){
                 int u=edges[j][0];
                 int v=edges[j][1];
                 if(probability[u]<probability[v]*succProb[j]){
                    probability[u]=probability[v]*succProb[j];
                    f=true;
                 }
                 if(probability[v]<probability[u]*succProb[j]){
                    probability[v]=probability[u]*succProb[j];
                    f=true;
                 }
               
            }
            if(f==false){
                break;
            }
        }
        return probability[end_node];
    }
};