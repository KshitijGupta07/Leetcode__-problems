class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<int>maxnum;
        int max=INT_MIN;
          for(int i=0;i<matrix[0].size();i++){
               int max=INT_MIN;
              for(int j=0;j<matrix.size();j++){
                  if(matrix[j][i]>=max){
                      max=matrix[j][i];
                  }
              }
              cout<<max<<" ";
              maxnum.push_back(max);
              
          }
          cout<<endl;
          
    
        
         for(int i=0;i<matrix.size();i++){
               
              for(int j=0;j<matrix[i].size();j++){
                  if(matrix[i][j]==-1){
                      matrix[i][j]=maxnum[j];
                  }
              }
             
              
          }
          
        return matrix;
        
    }
};