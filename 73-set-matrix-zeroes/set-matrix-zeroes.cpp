class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstcol=false;
        bool firstrow=false;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
                 firstcol=true;
            }
        }
        
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[0][i]==0){
                firstrow=true;
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

        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]==0){
                for(int j=0;j<matrix[0].size();j++){
                     matrix[i][j]=0;
                }
            }
        }
        for(auto j:matrix){
            for(auto k:j){
                cout<<k<<" ";
            }
            cout<<endl;
        }
        for(int j=1;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                for(int i=0;i<matrix.size();i++){
                    matrix[i][j]=0;
                }
            }
        }
        if(firstcol==true){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
        if(firstrow==true){
            for(int i=0;i<matrix[0].size();i++){
                matrix[0][i]=0;
            }
        }
        
    }
};