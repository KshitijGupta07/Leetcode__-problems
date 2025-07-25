class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int a=ans.back()[0];
            int b=ans.back()[1];
            int c=intervals[i][0];
            int d=intervals[i][1];
            if(b>=c){
                a=min(a,c);
                b=max(b,d);
                
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