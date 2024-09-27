class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count1=0;
        int count2=0;
        int count=-1;
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int k=0;k<grid[0].size();k++){
                if(grid[i][k]==2){
                    q.push({i,k});
                    count2++;
                }
                if(grid[i][k]==1){
                    count1++;
                }
            }
        }
        if(count1==0){
            return 0;
        }
        if(count2==0){
            return -1;
        }
        vector<int>a{1,0,-1,0};
        vector<int>b{0,1,0,-1};
        while(q.empty()==false){
            int size=q.size();
            while(size--){
            pair<int,int>front=q.front();
            q.pop();
            int x=front.first;
            int y=front.second;
            for(int i=0;i<4;i++){
               int newx=x+a[i];
               int newy=y+b[i];
               if(newx>=0&&newx<grid.size()&&newy>=0&&newy<grid[0].size()&&grid[newx][newy]==1){
                grid[newx][newy]=2;
                count1--;
                q.push({newx,newy});
               }
            }
            }
            count++;

        } 
        cout<<count1<<endl;
        if(count1==0){
        return count;
        }
        return -1;

    }
};