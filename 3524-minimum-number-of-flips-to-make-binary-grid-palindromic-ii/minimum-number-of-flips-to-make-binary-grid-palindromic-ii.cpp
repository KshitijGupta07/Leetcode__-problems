class Solution {
public:

    int minFlips(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size() ;
        int ans=0;
        map<pair<int,int>,bool>visitedpair;
        for(int i=0;i<m/2;i++){
            
            for(int j=0;j<n/2;j++){
                int count=0;
                if(grid[i][j]==1&&visitedpair[{i,j}]==false){
                    visitedpair[{i,j}]=true;
                    count++;
                }
                if(grid[m-1-i][n-1-j]==1&&visitedpair[{m-i-1,n-1-j}]==false){
                    visitedpair[{m-i-1,n-1-j}]=true;
                    count++;
                }
                if(grid[m-1-i][j]==1&&visitedpair[{m-1-i,j}]==false){
                    visitedpair[{m-1-i,j}]=true;
                    count++;
                }
                if(grid[i][n-1-j]==1&&visitedpair[{i,n-1-j}]==false){
                    visitedpair[{i,n-1-j}]=true;
                    count++;
                }
                   ans+=min(count,4-count);
            }
            
             
            
        }
        if(m%2==0&&n%2==0){
            return ans;
        }
        int change=0;
        int palinones=0;
         if(m%2==1){
            for(int i=0;i<n/2;i++){
                if(grid[m/2][i]==1&&grid[m/2][n-i-1]==1)palinones++;
                if(grid[m/2][i]!=grid[m/2][n-i-1]){
                     change++;
                     ans++;
                }
            }
         }
         if(n%2==1){
              for(int i=0;i<m/2;i++){
                if(grid[i][n/2]==1&&grid[m-i-1][n/2]==1)palinones++;
                if(grid[m-i-1][n/2]!=grid[i][n/2]){
                     change++;
                     ans++;
                }
            }
         }
         if(change==0&&palinones%2==1){
            ans=ans+2;
         }
         if(m%2==1&&n%2==1){
            if(grid[m/2][n/2]==1){
            ans++;
            }
         }
        return ans;
    }
};