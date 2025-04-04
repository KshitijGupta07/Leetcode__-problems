class Solution {
public:
    bool safe(int i,int j,vector<string>&temp,int n){
        int count=1;
        int count1=1;
        int count2=1;
        
        for(int x=0;x<n;x++){
            if(temp[i][x]=='Q'&&x!=j){
                count++;
            }
        }
        for(int x=0;x<n;x++){
            if(temp[x][j]=='Q'&&x!=i){
                count1++;
                
            }
        }
        int a=i;
        int b=j;
        while(a>-1&&b>-1){
          if(temp[a][b]=='Q'&&a!=i&&b!=j){
            count2++;
          }
          a-=1;
          b-=1;
        }
        a=i;
        b=j;
        while(a<n&&b<n){
            if(temp[a][b]=='Q'&&a!=i&&b!=j){
                count2++;
            }
            a++;
            b++;
        }
        a=i;
        b=j;
        while(a<n&&b>-1){
            if(temp[a][b]=='Q'&&a!=i&&b!=j){
                count2++;
            }
            a++;
            b--;
        }
        a=i;
        b=j;
        while(a>-1&&b<n){
             if(temp[a][b]=='Q'&&a!=i&&b!=j){
                count2++;
            }
            a--;
            b++;
        }
        cout<<count1<<" "<<count2<<" "<<count<<endl;
        if(count1<2&&count2<2&&count<2){
            return true;
        }
        return false;
    }
    void solve(int n,int i,vector<string>&temp,vector<vector<string>>&ans){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<n;j++){
             if(safe(i,j,temp,n)){
                temp[i][j]='Q';
                solve(n,i+1,temp,ans);
                temp[i][j]='.';
             }
             
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp;
        for(int i=0;i<n;i++){
            string x="";
            for(int j=0;j<n;j++){
              x.push_back('.');
            }
            temp.push_back(x);
        }
        solve(n,0,temp,ans);
        return ans;
    }
};