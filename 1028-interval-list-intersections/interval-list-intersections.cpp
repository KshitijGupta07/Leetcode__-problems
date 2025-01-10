class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        for(int i=0;i<firstList.size();i++){
            secondList.push_back(firstList[i]);
        }
        sort(secondList.begin(),secondList.end());
        vector<vector<int>>ans;
        for(int i=0;i<secondList.size()-1;i++){
            for(int j=i+1;j<secondList.size();j++){
                if(secondList[i][1]<secondList[j][0]){
                    break;
                }
                else{
                    int a=max(secondList[i][0],secondList[j][0]);
                    int b=min(secondList[i][1],secondList[j][1]);
                    ans.push_back({a,b});
                }
            }
        }
        return ans;
    }
};