class Solution {
public:
 int solve(vector<vector<int>>&triangle,int i,int j){
    if(i>=triangle.size()){
        return 0;
    }
    int x=triangle[i][j]+solve(triangle,i+1,j);
    int y=triangle[i][j]+solve(triangle,i+1,j+1);
    return min(x,y);
 }
  
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int>temp=triangle.back();
        
        for(int i=triangle.size()-2;i>=0;i--){
            vector<int>curr(i+1,0);
            for(int j=0;j<triangle[i].size();j++){
                   curr[j]=triangle[i][j]+min(temp[j],temp[j+1]);
            }
            temp=curr;
        }
    
        return temp[0];
    }
};