class Solution {
public:
 
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
           vector<vector<int>>visited(mat.size(),vector<int>(mat[0].size(),0));
         queue<pair<int,int>>q;
         vector<int>a{1,-1,0,0};
         vector<int>b{0,0,1,-1};
           for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    
                    mat[i][j]=INT_MAX;
                }
                else{
                    q.push({i,j});
                }
            }
           }
           while(q.empty()==false){
            pair<int,int>front=q.front();
            q.pop();
             int x=front.first;
             int y=front.second;
             for(int i=0;i<4;i++){
                if(x+a[i]>=0&&x+a[i]<mat.size()&&y+b[i]>=0&&y+b[i]<mat[0].size()&&mat[x+a[i]][y+b[i]]>1+mat[x][y]&&visited[x+a[i]][y+b[i]]==0){
                    mat[x+a[i]][y+b[i]]=1+mat[x][y];
                    visited[x+a[i]][y+b[i]]=1;
                    q.push({x+a[i],y+b[i]});
                }
             }
           }
           return mat;
    }
};