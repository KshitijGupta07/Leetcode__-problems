class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<int>>ans;
        vector<vector<int>>countX;
        int counter=0;
        for(int i=0;i<grid.size();i++){
            vector<int>ans1;
            vector<int>c;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='X'){
                    ans1.push_back(1);
                    counter++;
                }
                else if(grid[i][j]=='Y'){
                    ans1.push_back(-1);
                }
                else{
                    ans1.push_back(0);
                }
                c.push_back(counter);
            }
            
            ans.push_back(ans1);
            c.push_back(counter);
            countX.push_back(c);
            ans1.clear();
            counter=0;
        }
        for(int i=0;i<ans.size();i++){
            int prefix=0;
            
            for(int j=0;j<ans[0].size();j++){
        
                    prefix+=ans[i][j];
                
                ans[i][j]=prefix;
                if(i>0){
                    ans[i][j]+=ans[i-1][j];
                }
                if(i>0){
                    countX[i][j]+=countX[i-1][j];
                }
                
            }
            prefix=0;
        }
        int count=0;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++){
                
               if(ans[i][j]==0&&countX[i][j]>0){
                  count++;
               }
            }
            cout<<endl;
            
        }
        return count;
    }
};