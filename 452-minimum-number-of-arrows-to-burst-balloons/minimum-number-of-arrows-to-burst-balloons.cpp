class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int start=points[0][0];
        int end=points[0][1];
        int i=1;
        int count=1;
        while(i<points.size()){
           if(end>points[i][0]){
            start=max(start,points[i][0]);
            end=min(end,points[i][1]);
            i++;
           }
           else if(end==points[i][0]){
            
            
            i++;
            
           }
           else{
            count++;
            start=points[i][0];
            end=points[i][1];
            i++;
           }
           
           
        }
        return count;
    }
};