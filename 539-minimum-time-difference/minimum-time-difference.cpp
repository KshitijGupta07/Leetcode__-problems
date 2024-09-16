class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
         vector<int>ans;
         for(int i=0;i<timePoints.size();i++){
            int h=0;
            int m=0;
            if(timePoints[i][0]=='0'&&timePoints[i][1]=='0'){
                 if(timePoints[i][3]=='0'&&timePoints[i][4]=='0'){
                      ans.push_back(1440);
                 }
                 else{
                    m=10*(timePoints[i][3]-'0')+(timePoints[i][4]-'0');
                    ans.push_back(m);
                 }
            }
            else{
                h=60*(10*(timePoints[i][0]-'0')+(timePoints[i][1]-'0'));
                m=10*(timePoints[i][3]-'0')+(timePoints[i][4]-'0');
                ans.push_back(h+m);
            }
         }
         sort(ans.begin(),ans.end());
         for(auto j:ans){
            cout<<j<<endl;
         }
         int mini=INT_MAX;
         for(int i=1;i<ans.size();i++){
            mini=min(mini,min(1440-ans[i]+ans[i-1],ans[i]-ans[i-1]));
         }
         return min(mini,min(1440-ans[ans.size()-1]+ans[0],ans[ans.size()-1]-ans[0]));
    }
};