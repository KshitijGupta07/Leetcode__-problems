class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int>value;
        for(int i=0;i<matrix.size();i++){
            
            for(int j=0;j<matrix.size();j++){
                value.push_back(matrix[i][j]);
                
                
            }
        }
          for(int i=0;i<matrix.size();i++){
            
            for(int j=0;j<matrix.size();j++){
                matrix[j][matrix.size()-1-i]=value[matrix.size()*i+j];
                
                
            }
        }
    }
};