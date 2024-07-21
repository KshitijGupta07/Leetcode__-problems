class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int rowindex=0;
        int colindex=c-1;
         
         while(rowindex<r&&colindex>-1){
            int element=matrix[rowindex][colindex];
            if(element==target){
                return true;
         }
           else if(element<target){
            rowindex++;
           }
           else{
            colindex--;
           }
         }
         return false;
    }
};