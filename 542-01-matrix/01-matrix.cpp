class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
           map<pair<int,int>,bool>m;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    m[{i,j}]=true;

                }
                else{
                    mat[i][j]=INT_MAX;
                }
            }
        }
        vector<int>dx{-1,1,0,0};
        vector<int>dy{0,0,-1,1};
        while(q.empty()==false){
            int x=q.front().first;
            int y=q.front().second;
q.pop();
             for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&ny>=0&&nx<mat.size()&&ny<mat[0].size()&&m[{nx,ny}]==false&&mat[nx][ny]>1+mat[x][y]){
                    mat[nx][ny]=1+mat[x][y];
                    q.push({nx,ny});
                    m[{nx,ny}]=true;
                }
             }
        }
        return mat;

    }
};