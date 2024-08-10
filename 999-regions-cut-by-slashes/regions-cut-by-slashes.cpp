class Solution {
public:
   int dfs(vector<vector<int>>&ans,int i,int j){
     if(i<0||j<0||i>=ans.size()||j>=ans[0].size()||ans[i][j]==1){
        return 0;
     }
      ans[i][j]=1;
      return 1+dfs(ans,i+1,j)+dfs(ans,i-1,j)+dfs(ans,i,j+1)+dfs(ans,i,j-1);
   }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>>ans(3*n,vector<int>(3*n,0));
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j];
                if(grid[i][j]=='/'){
                    ans[i*3][j*3+2]=1;
                    ans[i*3+1][j*3+1]=1;
                    ans[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\'){
                    ans[i*3][j*3]=1;
                    ans[i*3+1][j*3+1]=1;
                    ans[i*3+2][j*3+2]=1;
                }
            }
         }
         int count=0;
         for(int i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
               if(dfs(ans,i,j)!=0){
                count++;
               }
            }
         }
         return count;

    }
};