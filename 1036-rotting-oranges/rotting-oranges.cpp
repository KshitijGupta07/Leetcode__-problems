class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        int count1=0;
        int ans=0;
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    count++;
                }
                else if(grid[i][j]==1){
                    count1++;
                }
            }
        }
        if(count1==0){
            return 0;
        }
        if(count==0){
            return -1;
        }
          vector<int>a{1,-1,0,0};
          vector<int>b{0,0,1,-1};
          while(q.empty()==false){
              int size=q.size();
              bool s=false;
              while(size!=0){
                 pair<int,int>front=q.front();
             
              q.pop();
                size--;
              
              int x=front.first;
              int y=front.second;
            
              for(int i=0;i<4;i++){
                int newx=x+a[i];
                int newy=y+b[i];
                if(newx>=0&&newx<grid.size()&&newy>=0&&newy<grid[0].size()&&grid[newx][newy]==1){
                    grid[newx][newy]=2;
                    count1--;
                    s=true;
                    q.push({newx,newy});
                }
               
              }
        
              }

               if(s==true){
              ans=ans+1;   
               } 
                
          }
          if(count1==0){
            return ans;
          }
          return -1;
    }
};