class Solution {
public:
    void solve(int x,int y ,vector<vector<int>>&ans,int size,int num){
        if(x>=ans.size()&&y>=ans.size()){
            return ;
        }
        if(size==1){
            ans[x][y]=num;
            return;
        }
        int l=size/2;
        int b=l*l;
        solve(x,y,ans,l,num+3*b);
        solve(x,y+l,ans,l,num);
        solve(x+l,y+l,ans,l,num+b);
        solve(x+l,y,ans,l,num+2*b);


    }
    vector<vector<int>> specialGrid(int N) {
        if(N==0){
            return {{0}};
        }  
        int size=pow(2,N);
        vector<vector<int>>ans(size,vector<int>(size));
        solve(0,0,ans,size ,0);
        return ans;

    }
};