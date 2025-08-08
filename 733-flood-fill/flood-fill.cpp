class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int original=image[sr][sc];
         queue<pair<int,int>>q;
         q.push({sr,sc});
         image[sr][sc]=color;
         map<pair<int,int>,bool>m;
         m[{sr,sc}]=true;
         vector<int>dx{1,-1,0,0};
         vector<int>dy{0,0,-1,1};
         while(q.empty()==false){
            int a=q.size();
            for(int i=0;i<a;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if(nx>=0&&ny>=0&&nx<image.size()&&ny<image[0].size()&&m[{nx,ny}]==false&&image[nx][ny]==original){
                        image[nx][ny]=color;
                        m[{nx,ny}]=true;
                        q.push({nx,ny});
                    }
                }
            }
         }
         return image;
    }
};