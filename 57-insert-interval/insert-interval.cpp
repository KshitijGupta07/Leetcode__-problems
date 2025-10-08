class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0){
            return {newInterval};
        }
        vector<vector<int>>ans;
        int index=-1;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
             if(newInterval[0]>intervals[i][1]){
                  ans.push_back(intervals[i]);
             }
             else if(newInterval[1]<intervals[i][0]){
                index=i;
                break;
                
                
             }
             else{
                
                  int a=intervals[i][0];
                 int b=intervals[i][1];
                 int c=newInterval[0];
                 int d=newInterval[1];
                 newInterval[0]=min(a,c);
                 newInterval[1]=max(b,d);
             }
        }
       cout<<newInterval[0]<<" "<<newInterval[1]<<endl;
        ans.push_back(newInterval);
        for(int i=index;i<intervals.size();i++){
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};