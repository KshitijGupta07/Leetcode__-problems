class Solution {
public:
    void solve(vector<int>&ans,int i,int j,int ri,int ci,vector<vector<int>>&matrix){
       
        for(int k=j;k<=ci;k++){
            ans.push_back(matrix[i][k]);
        }
        i+=1;
         if(i>ri||j>ci){
            return;
        }
        for(int k=i;k<=ri;k++){
            ans.push_back(matrix[k][ci]);
        }
        ci-=1;
         if(i>ri||j>ci){
            return;
        }
        for(int k=ci;k>=j;k--){
            ans.push_back(matrix[ri][k]);
        }
        ri-=1;
         if(i>ri||j>ci){
            return;
        }
        for(int k=ri;k>=i;k--){
            ans.push_back(matrix[k][j]);
        }
        j+=1;
         if(i>ri||j>ci){
            return;
        }
        solve(ans,i,j,ri,ci,matrix);


    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        solve(ans,0,0,matrix.size()-1,matrix[0].size()-1,matrix);
        return ans;
    }
};