class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(int i=0;i<intervals.size();i++){
            if(ans.empty()==true){
                  
                  ans.push_back(intervals[i]);
            }
            else if(intervals[i][0]<=ans.back()[1]){
              int a=min(intervals[i][0],ans.back()[0]);
                  int b=max(intervals[i][1],ans.back()[1]);
                  ans.pop_back();
                  ans.push_back({a,b});
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};