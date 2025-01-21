class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

    
        int n=grid[0].size();
        if(n==1){
            return 0;
        }
       
        vector<long long >prefix1(grid[0].size());
        prefix1[0]=grid[0][0];
        for(int i=1;i<grid[0].size();i++){
            long long element=grid[0][i];
           prefix1[i]+=element+prefix1[i-1]; 
        }
        vector<long long >prefix2(grid[0].size());
        prefix2[0]=grid[1][0];
        for(int i=1;i<grid[0].size();i++){
            long long element=grid[1][i];
            prefix2[i]+=element+prefix2[i-1];
        }
        long long ans=pow(2,40)-1;
        
        for(int i=0;i<grid[0].size();i++){
             if(i==n-1){
                ans=min(ans,prefix2[n-2]);
             }
             else{
                 if(i==0){
                ans=min(ans,prefix1[n-1]-prefix1[i]);
                 }
                 else{
                    long long element=max(prefix1[n-1]-prefix1[i],prefix2[i-1]);
                    ans=min(ans,element);
                 }

             }
        }
        
        return ans;
    }
};