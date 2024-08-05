class Solution {
public:
   int solve(int n,int i,vector<int>&temp){
    if(i>n){
        return 1;
    }
    int ans=0;
     for(int j=1;j<=n;j++){
        if(temp[j]==0&&(j%i==0||i%j==0)){
            temp[j]=i;
             ans+=solve(n,i+1,temp);
             temp[j]=0;
        }
     }
     return ans;
   }
    int countArrangement(int n) {
        vector<int>temp(n+1);
        int ans=solve(n,1,temp);
        return ans;
        
    }
};