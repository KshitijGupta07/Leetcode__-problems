class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>>ans(isWater.size(),vector<int>(isWater[0].size(),-1));
        queue<vector<int>>q;
        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){
                if(isWater[i][j]==1){
                    q.push({0,i,j});
                    ans[i][j]=0;
                }
            }
        }
        vector<int>a{-1,1,0,0};
        vector<int>b{0,0,-1,1};
        while(q.empty()==false){
            vector<int>front=q.front();
            q.pop();
            int h=front[0];
            int x=front[1];
            int y=front[2];
            for(int i=0;i<4;i++){
                int newx=x+a[i];
                int newy=y+b[i];
                if(newx>=0&&newx<ans.size()&&newy>=0&&newy<ans[0].size()&&ans[newx][newy]==-1){
                    ans[newx][newy]=h+1;
                    q.push({ans[newx][newy],newx,newy});
                }
            }
        }
        return ans;
        
    }
};