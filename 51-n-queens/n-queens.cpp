class Solution {
public:
   bool check(int i,int j,vector<string>temp,int n){
       for(int x=0;x<n;x++){
        if(temp[x][j]=='Q'&&x!=i){
            return false;
        }
       }
       for(int x=0;x<n;x++){
        if(temp[i][x]=='Q'&&x!=j){
            return false;
        }
       }
       int x=i;
       int y=j;
       while(x>-1&&y>-1){
         if(temp[x][y]=='Q'&&(x!=i||y!=j)){
            return false;
         }
         x-=1;
         y-=1;
       }
       x=i;
       y=j;
       while(x>-1&&y<n){
        if(temp[x][y]=='Q'&&(x!=i||y!=j)){
            return false;
        }
        x-=1;
        y+=1;
       }
       x=i;
       y=j;
       while(x<n&&y>-1){
        if(temp[x][y]=='Q'&&(x!=i||y!=j)){
            return false;
        }
        x+=1;
        y-=1;
       }
       x=i;
       y=j;
       while(x<n&&y<n){
        if(temp[x][y]=='Q'&&(x!=i||y!=j)){
            return false;
        }
        x+=1;
        y+=1;
       }
       return true;
   }
   void solve(int i,vector<string>temp,vector<vector<string>>&ans,int n){
     if(i>=n){
        ans.push_back(temp);
        return;
     }
     for(int j=0;j<n;j++){
        
         if(check(i,j,temp,n)){
            temp[i][j]='Q';
            solve(i+1,temp,ans,n);
            temp[i][j]='.';
            
         }
     }
    
   }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        
        vector<string>temp;
        for(int i=0;i<n;i++){
            string t="";
            for(int j=0;j<n;j++){
               t.push_back('.');
            }
            temp.push_back(t);
        }
        int i=0;
        solve(i,temp,ans,n);
        return ans;
        
    }
};