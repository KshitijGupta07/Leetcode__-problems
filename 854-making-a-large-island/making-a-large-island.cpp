class Solution {
public:
   int solve(vector<vector<int>>&grid,int i,int j,int island){
    int n=grid.size();
    if(i<0||i>=n||j<0||j>=n||grid[i][j]!=1){
        return 0;
    }
    grid[i][j]=island;
    
    
     
    
     
     return 1+solve(grid,i+1,j,island)+solve(grid,i-1,j,island)+solve(grid,i,j+1,island)+solve(grid,i,j-1,island);
   }
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid.size(),false));
        int ans=0;
        int n=grid.size();
        map<int,int>m;
        int island=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                  if(grid[i][j]==1){
                    
                    
                    m[island]=solve(grid,i,j,island);
                    island++;

                  }
                  
            }
        }
        if(m.size()==0){
            return 1;
        }
        if(m.size()==1){
            if(m.begin()->second==n*n){
                return n*n;
            }
            else{
                return m.begin()->second+1;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int c=1;
                    unordered_set<int>v;
                    if(i+1<n){
                       v.insert(grid[i+1][j]);
                    }
                    if(j+1<n){
                        v.insert(grid[i][j+1]);
                    }
                    if(i-1>=0){
                        v.insert(grid[i-1][j]);
                    }
                    if(j-1>=0){
                        v.insert(grid[i][j-1]);
                    }
                    int sum=1;
                    for(auto j:v){
                          sum+=m[j];
                    }
                    ans=max(ans,sum);

                }
            }
        }


          
        
        return ans;
    }
};