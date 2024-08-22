class Solution {
public:
void solve(int n, char* result) {
    int halfLength = n / 2;
    bool isOdd = n % 2 != 0;
    
    char h[50001];  
    char palindrome[100001];  
    

    for (int i = 0; i < halfLength; ++i) {
        h[i] = '9';
    }
    h[halfLength] = '\0';

    
    auto isDivisibleBy7 = [](const char* numStr, int length) {
        long long m = 0;
        for (int i = 0; i < length; ++i) {
            m = (m * 10 + (numStr[i] - '0')) % 7;
        }
        return m == 0;
    };

    
    auto gPalindrome = [](const char* h, int halfLength, bool isOdd, char* result) {
        int i;
        for (i = 0; i < halfLength; ++i) {
            result[i] = h[i];
        }
        if (isOdd) {
            result[i++] = '0';  
        }
        for (int j = halfLength - 1; j >= 0; --j) {
            result[i++] = h[j];
        }
        result[i] = '\0';
    };


    auto decrementHalf = [](char* h, int halfLength) {
        for (int i = halfLength - 1; i >= 0; --i) {
            if (h[i] > '0') {
                h[i]--;
                return;
            }
            h[i] = '9';
        }
    };

    while (true) {
        gPalindrome(h, halfLength, isOdd, palindrome);
        
        if (isOdd) {
            for (int middleDigit = 9; middleDigit >= 0; --middleDigit) {
                palindrome[halfLength] = middleDigit + '0';
                if (isDivisibleBy7(palindrome, n)) {
                    for (int i = 0; i <= n; ++i) {
                        result[i] = palindrome[i];
                    }
                    return;
                }
            }
        } else if (isDivisibleBy7(palindrome, n)) {
            for (int i = 0; i <= n; ++i) {
                result[i] = palindrome[i];
            }
            return;
        }
        
        decrementHalf(h, halfLength);
    }
}
    string largestPalindrome(int n, int k) {
        if(k==1||k==3||k==9){
            string ans="";
            for(int i=1;i<=n;i++){
                ans.push_back('9');
            }
            return ans;
        }
        if(k==2){
            if(n==1){
                return "8";
            }
            else{
                string ans="";
                ans.push_back('8');
                for(int i=2;i<=n;i++){
                    if(i==n){
                        ans.push_back('8');
                    }
                    else{
                     ans.push_back('9');
                    }
                }
                return ans;
            }
        }
        if(k==4){
            if(n==1){
                return "8";
            }
            if(n==2){
                return "88";
            }
            string ans="";
            ans.push_back('8');
            ans.push_back('8');
            for(int i=3;i<=n;i++){
                if(i==n-1||i==n){
                    ans.push_back('8');
                    
                }
                else{
                    ans.push_back('9');
                }
            }
            return ans;
        }
        if(k==8){
                 if(n==1){
                return "8";
            }
            if(n==2){
                return "88";
            }
            if(n==3){
                return "888";
            }
            string ans="";
            ans.push_back('8');
            ans.push_back('8');
            ans.push_back('8');
            for(int i=4;i<=n;i++){
                if(i==n-1||i==n||i==n-2){
                    ans.push_back('8');
                    
                }
                else{
                    ans.push_back('9');
                }
            }
            return ans;
        }
        if(k==5){
            if(n==1){
                return "5";
            }
            string ans="";
            ans.push_back('5');
            for(int i=2;i<=n;i++){
                if(i==n){
                    ans.push_back('5');
                }
                else{
                    ans.push_back('9');
                }
            }
            return ans;
        }
        if(k==6){
            if(n%2==1){
                string ans="";
                ans.push_back('8');
                for(int i=2;i<=n/2;i++){
                   ans.push_back('9'); 
                }
                if(n==1){
                    return "6";
                }
              
                if(n==3){
                    return "888";
                }
                string s=ans;
                reverse(ans.begin(),ans.end());
                s.push_back('8');
                s=s+ans;
                return s;
            }
            else{
                  if(n==2){
                    return "66";
                }
                string ans="";
                ans.push_back('8');
                for(int i=2;i<n/2;i++){
                    ans.push_back('9');
                }
                string s=ans;
                reverse(ans.begin(),ans.end());
                
                s.push_back('7');
                s.push_back('7');
                s+=ans;
                return s;

            }
        }
        if(n==1){
            return "7";
        }
        if(n==2){
            return "77";
        }
        
        map<int,string>m;
        m[0]="";
        m[1]="7";
        m[2]="77";
        m[3]="959";
        m[4]="9779";
        m[5]="99799";
        m[6]="999999";
        m[7]="9994999";
        m[8]="99944999";
        m[9]="999969999";
        m[10]="9999449999";
        m[11]="99999499999";
        m[12]="999999999999";
     int count=(n-n%12)/6;
     string ans="";
     int i=0;
     if(n%12==0){
        while(i!=n){
            ans.push_back('9');
            i++;
        }
        return ans;
     }
     while(i!=count/2 ){
        ans+="999999";
        i++;
     }
     ans+=m[n%12];
      i=0;
      while(i!=count/2){
        ans+="999999";
        i++;
      }
     return ans;

    }
};