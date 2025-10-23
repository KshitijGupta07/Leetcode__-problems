class Solution {
public:
  bool safe(int i,int j,int n,vector<string>&board){
    
     for(int x=0;x<n;x++){
        if(board[x][j]=='Q'&&x!=i){
            return false;
        }
     }

    
     for(int x=0;x<n;x++){
        if(board[i][x]=='Q'&&x!=j){
            return false;
        }
     }
     
     int a=i;
     int b=j;
     while(a>=0&&b>=0){
           if(board[a][b]=='Q'){
               if(a!=i||b!=j){
                return false;
               }
           }
           a--;
           b--;
     }
    
     a=i;
     b=j;
    
     while(a>=0&&b<n){
        if(board[a][b]=='Q'){
            if(a!=i||b!=j){
                return false;
            }
        }
        a--;
        b++;
     }
    
     a=i;
     b=j;
    
     while(a<n&&b<n){
        if(board[a][b]=='Q'){
             if(a!=i||b!=j){
                return false;
             }
        }
        a++;
        b++;
     }
     
     a=i;
     b=j;
    
     while(a<n&&b>=0){
        if(board[a][b]=='Q'){
            if(a!=i||b!=j){
                return false;
            }

        }
        a++;
        b--;
     }
     
     return true;

  }
   void solve(vector<vector<string>>&ans,vector<string>&board,int n,int i){
    if(i==n){
        ans.push_back(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(safe(i,j,n,board)){
            cout<<safe(i,j,n,board)<<endl;
            board[i][j]='Q';
            solve(ans,board,n,i+1);
            board[i][j]='.';
        }
    }
   }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board;
        string temp="";
        for(int i=0;i<n;i++){
            temp.push_back('.');
        }
        for(int i=0;i<n;i++){
            board.push_back(temp);
        }
        vector<vector<string>>ans;
        int i=0;
        solve(ans,board,n,i);
        return ans;
    }
};