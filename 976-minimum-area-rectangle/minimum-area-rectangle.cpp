class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<pair<int,int>,bool>m;
        sort(points.begin(),points.end());
        for(int i=0;i<points.size();i++){
            pair<int,int>x={points[i][0],points[i][1]};
            m[x]=true;
            
        }
        int ans=INT_MAX;
        for(int i=0;i<points.size()-1;i++){
          for(int j=i+1;j<points.size();j++){
               int x1=points[i][0];
               int y1=points[i][1];
               int x2=points[j][0];
               int y2=points[j][1];
               if(x2>x1&&y2>y1){
                 if(m[{x2,y1}]==true&&m[{x1,y2}]==true){
                     int ar=(x2-x1)*(y2-y1);
                     ans=min(ans,ar);
                 }
               }
          }
    }
    if(ans==INT_MAX){
        return 0;
    }
    return ans;
    }
};