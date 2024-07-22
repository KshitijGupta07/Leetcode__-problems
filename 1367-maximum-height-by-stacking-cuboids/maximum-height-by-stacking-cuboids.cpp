class Solution {
public:
bool check(vector<int>p,vector<int>c){
    if(p[0]<=c[0]&&p[1]<=c[1]&&p[2]<=c[2]){
        return true;
    }
    return false;
}
  int solve(vector<vector<int>>& cuboids,int n){
      vector<int>curr(n+1,0);
      vector<int>next(n+1,0);
      
      for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
            int take=0;
            if(j==-1||check(cuboids[j],cuboids[i])){
                take=next[i+1]+cuboids[i][2];
            }
            int notake=next[j+1];
            curr[j+1]=max(take,notake);
        }
        next=curr;
      }
      return next[0];
  }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(int i=0;i<cuboids.size();i++){
            sort(cuboids[i].begin(),cuboids[i].end());
        }

        sort(cuboids.begin(),cuboids.end());
        return solve(cuboids,cuboids.size());
    

    }
};