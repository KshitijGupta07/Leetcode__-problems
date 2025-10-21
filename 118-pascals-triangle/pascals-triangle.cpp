class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>temp;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==1){
            return ans;
        }
        for(int i=2;i<=numRows;i++){
            vector<int>curr;
            curr.push_back(1);
            for(int j=1;j<i-1;j++){
                curr.push_back(temp[j]+temp[j-1]);
            }
            curr.push_back(1);
            ans.push_back(curr);
            temp=curr;
        }
        return ans;
    }
};