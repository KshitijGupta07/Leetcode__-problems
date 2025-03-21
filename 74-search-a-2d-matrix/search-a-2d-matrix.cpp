class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0;
        int end=matrix.size()*matrix[0].size()-1;
        int col=matrix[0].size();
        while(start<=end){
            int mid=(start+end)/2 ;
            if(matrix[mid/col][mid%col]==target){
                return true;
            }
            else if(matrix[mid/col][mid%col]>target){
                end=mid-1;
            }
            else{
                start=mid +1;
            }
        }
        return false;
    }
};