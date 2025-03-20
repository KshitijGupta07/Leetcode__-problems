class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        int i=1;
        while(i<intervals.size()){
            int a=ans.back()[0];
            int b=ans.back()[1];
            int c=intervals[i][0];
            int d=intervals[i][1];
            if(b<c){
                ans.push_back(intervals[i]);
            }
            else{
                int x=min(a,c);
                int y=max(b,d);
                ans.pop_back();
                ans.push_back({x,y});
            }
            i++;
        }
        return ans;
    }
};