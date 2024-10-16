class Solution {
public:
  void solve(vector<vector<int>>& matrix,int &firstrow,int &lastrow,int& firstcolumn,int& lastcolumn,vector<int>&ans){
     
         for(int i=firstcolumn;i<=lastcolumn;i++){
            ans.push_back(matrix[firstrow][i]);
         }
         firstrow=firstrow+1;
         if(firstrow>matrix.size()||firstrow>lastrow){
            return;
         }
         for(int i=firstrow;i<=lastrow;i++){
            ans.push_back(matrix[i][lastcolumn]);
         }
         
         lastcolumn=lastcolumn-1;
         if(lastcolumn<0||lastcolumn<firstcolumn){
            return;
         }
         for(int i=lastcolumn;i>=firstcolumn;i--){
            ans.push_back(matrix[lastrow][i]);
         }
          lastrow=lastrow-1;
          if(lastrow<0||lastrow<firstrow){
            return;
          }
          for(int i=lastrow;i>=firstrow;i--){
            ans.push_back(matrix[i][firstcolumn]);
          }
          firstcolumn=firstcolumn+1;
          if(firstcolumn>=matrix[0].size()||firstcolumn>lastcolumn){
            return;
          }
          solve(matrix,firstrow,lastrow,firstcolumn,lastcolumn,ans);
  
  }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int firstrow=0;
        int lastrow=matrix.size()-1;
        int firstcolumn=0;
        int lastcolumn=matrix[0].size()-1;

        solve(matrix,firstrow,lastrow,firstcolumn,lastcolumn,ans);
        return ans;
    }
};