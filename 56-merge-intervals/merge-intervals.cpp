class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(int i=0;i<intervals.size();i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            else{
                if(ans.back()[1]>=intervals[i][0]){
                    int a=ans.back()[0];
                    int b=intervals[i][0];
                    int c=ans.back()[1];
                    int d=intervals[i][1];
                    ans.pop_back();
                       ans.push_back({min(a,b),max(c,d)});
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};