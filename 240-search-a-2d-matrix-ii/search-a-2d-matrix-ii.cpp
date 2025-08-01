class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int r=0;
        int c=matrix[0].size()-1;
        while(r<m&&c>=0){
            if(matrix[r][c]==target){
                return true;
            }
            else if(matrix[r][c]>target){
                c--;
            }
            else{
                r++;
            }
        }
        return false;
    }
};