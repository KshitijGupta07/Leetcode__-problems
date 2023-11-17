class Solution {
public:
    long long coloredCells(long long int n) {
        long long ans=pow(n,2)+pow(n-1,2) ;
       return ans;
    }
};