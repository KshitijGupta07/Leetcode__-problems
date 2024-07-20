class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int>ans;
        if(envelopes.size()==1){
            return 1;
        }
        sort(envelopes.begin(),envelopes.end(),[](const auto& a,const auto& b){
            if(a[0]!=b[0])return a[0]<b[0];
            return a[1]>b[1];
        });
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            int a=ans.back();
            if(a<envelopes[i][1]){
                 ans.push_back(envelopes[i][1]);
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                if(index<ans.size())
                ans[index]=envelopes[i][1];
                else{
                    ans.push_back(envelopes[i][1]);
                }
            }
        }
        return ans.size();
    }
};