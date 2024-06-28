class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>p;
          int sum=INT_MIN;
        for(int i=0;i<points.size();i++){
            while(p.empty()==false&&points[i][0]-p.top().second>k){
                p.pop();
            }
            if(p.empty()==false){
              sum=max(sum,points[i][0]+points[i][1]+p.top().first);
            }
            
            p.push({points[i][1]-points[i][0],points[i][0]});
            
        }
        return sum;
    }
};