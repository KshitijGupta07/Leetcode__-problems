class Solution {
public:

   int dfs(int i,int j,vector<vector<int>>&grid,map<pair<int,int>,bool>&visited){
    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0||visited[{i,j}]==true){
        return 0;
    }
        
       visited[{i,j}]=true;
       return 1+dfs(i+1,j,grid,visited)+dfs(i-1,j,grid,visited)+dfs(i,j+1,grid,visited)+dfs(i,j-1,grid,visited);
   }
   bool help(vector<vector<int>>&grid){
    map<pair<int,int>,bool>p;
    int ans=0;

          for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                   int size=dfs(i,j,grid,p);
                    if(size>0){
                         
                        ans++;
                        
                        
                    }
            }  
            
        }       
            
        if(ans!=1){
            return false;
        }
        return true;
    
   }
    int minDays(vector<vector<int>>& grid) {
        
       
        vector<pair<int,int>>p;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    p.push_back({i,j});
                }
            }
        }
        if(help(grid)==false){
            return 0;
        }
        
        if(p.size()==4){
            if(p[0].first==p[1].first&&p[2].first==p[3].first&&p[0].first+1==p[2].first){
                if(p[0].second+1==p[1].second&&p[2].second+1==p[3].second&&p[0].second==p[2].second){
                     return 2;
                }
            }
            else{
                return 1;
            }
        }
        
        for(int i=0;i<p.size();i++){
             grid[p[i].first][p[i].second]=0;
             if(help(grid)==false){
            
                return 1;
             }
             else{
                
                  grid[p[i].first][p[i].second]=1;
             }
           
        }
      
    
         
        return 2;
    }
};