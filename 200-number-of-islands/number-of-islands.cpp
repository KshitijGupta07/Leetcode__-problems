class Solution {
public:
   void solve(vector<vector<char>>&grid,vector<vector<bool>>&visited,int i,int j,int m,int n){
    if(i<0||j<0||i>=m||j>=n||visited[i][j]==true||grid[i][j]=='0'){
        return ;
    }
     visited[i][j]=true;
     solve(grid,visited,i,j+1,m,n);
     solve(grid,visited,i,j-1,m,n);
     solve(grid,visited,i+1,j,m,n);
     solve(grid,visited,i-1,j,m,n);
   }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==false&&grid[i][j]=='1'){
                    solve(grid,visited,i,j,m,n);
                    ans++;
                }
            }
        }
        return ans;
    }
};