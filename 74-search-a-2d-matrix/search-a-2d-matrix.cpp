class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0;
        int end=(matrix.size()*matrix[0].size())-1;
        int m=matrix.size();
        int n=matrix[0].size();
        while(start<=end){
            int mid=(start+end)/2 ;
            cout<<mid<<endl;;
            int r=mid/n;
            int c=mid%n;
            if(matrix[r][c]==target){
                return true;
            }
            else if(matrix[r][c]>target){
                end--;
            }
            else{
                start++;
            }
        }
        return false;
    }
};