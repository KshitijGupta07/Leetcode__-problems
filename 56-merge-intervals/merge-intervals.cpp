class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        if(intervals.size()==1){
            return intervals;
        }
    
        for(int i=0;i<intervals.size();i++){
            if(ans.empty()||ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=max(intervals[i][1],ans.back()[1]);
            }

        }
        return ans;
    }
};