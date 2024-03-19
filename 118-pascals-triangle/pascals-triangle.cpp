class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal;
        if(numRows==1){
            pascal.push_back({1});

        }
        else if(numRows==2){
            pascal.push_back({1});
            pascal.push_back({1,1});
        }
        else{
            pascal.push_back({1});
              pascal.push_back({1,1});
              for(int i=2;i<numRows;i++){
                vector<int>p;
                p.push_back(1);
                for(int j=1;j<i;j++){
                  p.push_back(pascal[i-1][j]+pascal[i-1][j-1]);
                }
                p.push_back(1);
                pascal.push_back(p);
                p.clear();
              }
        }
        return pascal;
    }
};