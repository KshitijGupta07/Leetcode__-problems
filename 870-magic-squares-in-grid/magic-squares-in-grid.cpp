class Solution {
public:
  bool check(int i,int j,vector<vector<int>>&grid){
    map<int,int>m;
    int element=1^2^3^4^5^6^7^8^9;
     for(int x=i;x<=i+2;x++){
        int sum=0;
        
        for(int y=j;y<=j+2;y++){
           sum+=grid[x][y];
           element=element^grid[x][y];
        
        }
        m[sum]++;
        
     }
     for(int y=j;y<=j+2;y++){
         int sum2=0;
        for(int x=i;x<=i+2;x++){
              sum2+=grid[x][y];
        }
        m[sum2]++;
     }
     int a=grid[i][j]+grid[i+2][j+2]+grid[i+1][j+1];
     int b=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
     m[a]++;
     m[b]++;
     if(m.size()==1&&element==0){
        return true;
     }
     return false;

    
  }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size()-1;
        int n=grid[0].size()-1;
        vector<pair<int,int>>ans;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i+2<=m&&j+2<=n){
                    ans.push_back({i,j});
                }
            }
        }
        if(ans.size()==0){
            return 0;
        }
        int count=0;
        
        for(auto j:ans){
            bool s=check(j.first,j.second,grid);
            if(s==true){
                count++;
            }
        }
        return count;
    }
};