class Solution {
public:
   void solve(vector<vector<int>>&matrix,int& i,int& j,int& m,int& n,vector<int>&ans){
    if(i>m||j>n){
        return;
    }
    cout<<i<<" "<<j<<" "<<m<<" "<<n<<endl;
     for(int x=j;x<=n;x++){
        ans.push_back(matrix[i][x]);
     }
     i+=1;
     for(int x=i;x<=m;x++){
        ans.push_back(matrix[x][n]);
     }
     n-=1;
       if(i>m||j>n){
        return;
    }
     for(int x=n;x>=j;x--){
        ans.push_back(matrix[m][x]);
     }
     m-=1;
     for(int x=m;x>=i;x--){
        ans.push_back(matrix[x][j]);
     }
     j+=1;
     solve(matrix,i,j,m,n,ans);
}
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size()-1;
        int n=matrix[0].size()-1;
        int i=0;
        int j=0;
        solve(matrix,i,j,m,n,ans);
        return ans;
    }
};