class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        map<pair<int,int>,bool>visited;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    
                    q.push({i,j});
                    visited[{i,j}]=true;
                }
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        if(count==0){
            return 0;
        }
        vector<int>a{-1,1,0,0};
        vector<int>b{0,0,-1,1};
        count=0;

        while(q.empty()==false){
            int x=q.size();
            bool check=false;
            for(int i=0;i<x;i++){
            pair<int,int>front=q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int newx=front.first+a[i];
                int newy=front.second+b[i];
                if(newx>=0&&newy>=0&&newx<grid.size()&&newy<grid[0].size()&&visited[{newx,newy}]==false&&grid[newx][newy]==1){
                    check=true;
                    grid[newx][newy]=2;
                    q.push({newx,newy});
                    visited[{newx,newy}]=true;
                }
            }
            }
            if(check==true){
                count++;
            }
            
        }
        for(auto j:grid){
            for(auto k:j){
                if(k==1){
                    return -1;
                }
            }
        }
        return count;
    }
};