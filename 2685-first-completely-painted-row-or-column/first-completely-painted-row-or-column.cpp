class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,int>m;
        map<int,int>index;
        int timer=1;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=timer;
            timer++;
            index[arr[i]]=i;

        }
        int ans=INT_MAX;
        for(int i=0;i<mat.size();i++){
            int x=INT_MAX;
            int y=mat[i][0];
            for(int j=1;j<mat[0].size();j++){
               if(m[y]<m[mat[i][j]]){
                  y=mat[i][j];
                  x=index[mat[i][j]];
               }
            }
            if(x==INT_MAX){
                ans=min(ans,index[mat[i][0]]);
            }
            else{
            ans=min(x,ans);
            }
        }
        
        for(int i=0;i<mat[0].size();i++){
            int y=mat[0][i];
            int x=INT_MAX;
            for(int j=1;j<mat.size();j++){
                if(m[y]<m[mat[j][i]]){
                    y=mat[j][i];
                    x=index[mat[j][i]];
                }
            }
            if(x==INT_MAX){
                ans=min(ans,index[mat[0][i]]);
            }
            else{
            ans=min(ans,x);
            }
        }
        
        return ans;
        
    }
};