class Solution {
public:
    int maxProduct(int n) {
        vector<int>digit;
        while(n>0){
            digit.push_back(n%10);
            n/=10;
        }
        sort(digit.begin(),digit.end());
        reverse(digit.begin(),digit.end());
        
        return digit[0]*digit[1];
    }
};