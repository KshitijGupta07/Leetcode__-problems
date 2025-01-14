class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        if(n==1){
            return 0;
        }
        string x="";
        string y="";
        for(int i=0;i<n/2 ;i++){
            x=x+"01";
            y=y+"10";
        }
        if(n%2==1){
            x.push_back('0');
            y.push_back('1');
        }
        int a=0;
        int b=0;
        int count0=0;
        int count1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                count0++;
            }
            if(s[i]=='1'){
                count1++;
            }
               if(x[i]==s[i]){
                a++;
               }
               if(y[i]==s[i]){
                b++;
               }
        }
        if(abs(count0-count1)>1){
            return -1;
        }
        if(a%2==1&&b%2==1){
            return -1;
        }
        if(a%2==0&&b%2==0){
            return min(a/2,b/2);
        }
        else if(a%2==0){
            return a/2;
        }
        return b/2;
    }
};