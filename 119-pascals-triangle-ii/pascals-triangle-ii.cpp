class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans(rowIndex+1,1);
        for(int i=rowIndex-1;i>0;i--){
            for(int j=1;j<=i;j++){
                ans[j]+=ans[j-1];
            }
        }
        return ans;
    }
};