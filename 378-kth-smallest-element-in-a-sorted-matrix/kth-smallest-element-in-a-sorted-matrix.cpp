class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>p;
        for(int i=0;i<matrix.size();i++){
            p.push({matrix[i][0],i,0});
        }
        int ans=0;
        int row=0;
        int col=0;
        for(int j=0;j<k;j++){
    
            vector<int>top=p.top();
            p.pop();
             row=top[1];
             col=top[2];
            ans=top[0];
            
            if(col+1<matrix[0].size()){
                p.push({matrix[row][col+1],row,col+1});
            }
        }
        return ans;
    }
};