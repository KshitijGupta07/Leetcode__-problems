class Solution {
public:
    bool isPalindrome(int x) {
        int a=x;
        int ans=0;
        while(x!=0){
            if(ans<INT_MAX/10&&ans>INT_MIN/10)
          ans=ans*10+x%10;
          x=x/10;
        }
        if(ans==a&&a>=0){
            return true;
        }
        return false;
    }
};