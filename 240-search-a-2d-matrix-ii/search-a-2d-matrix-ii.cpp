class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=0;
        int c=matrix[0].size()-1;
        while(r<matrix.size()&&c>=0){
            if(matrix[r][c]==target){
                return true;
            }
            else if(matrix[r][c]>target){
                c-=1;
            }
            else{
                r+=1;
            }
        }
        return false;
    }
};