class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstrow=false;
        bool firstcolumn=false;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
                firstcolumn=true;
                break;
            }
        }
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[0][i]==0){
                firstrow=true;
                break;
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<matrix[0].size();i++){
            if(matrix[0][i]==0){
                for(int j=1;j<matrix.size();j++){
                    matrix[j][i]=0;
                }
            }
        }
        for(int j=1;j<matrix.size();j++){
            if(matrix[j][0]==0){
                for(int i=1;i<matrix[0].size();i++){
                    matrix[j][i]=0;
                }
            }
        }
        if(firstrow){
            for(int i=0;i<matrix[0].size();i++){
                    matrix[0][i]=0;
            }
        }
        if(firstcolumn){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
        return;
    }
};