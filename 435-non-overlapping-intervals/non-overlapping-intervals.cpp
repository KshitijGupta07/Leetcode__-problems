class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        int count=1;
        for(int i=1;i<intervals.size();i++){
            if(end<=intervals[i][0]){
                start=intervals[i][0];
                end=intervals[i][1];
                count++;
            }
            else{
                start=max(start,intervals[i][0]);
                end=min(end,intervals[i][1]);
            }
        }
        return intervals.size()-count;
    }
};