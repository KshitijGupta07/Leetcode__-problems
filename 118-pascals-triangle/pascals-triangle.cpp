class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1){
            return {{1}};
        }
        vector<vector<int>>ans;
        ans.push_back({1});
        vector<int>prev{1};
        
        for(int i=2;i<=numRows;i++){
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<i-1;j++){
                temp.push_back(prev[j-1]+prev[j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            prev=temp;

        }
        return ans;
    }
};