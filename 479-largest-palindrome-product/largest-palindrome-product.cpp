class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1){
            return 9;
        }
    long   long    low=pow(10,n-1);
    long long      high=pow(10,n)-1;
        string a="";
        for(long long  i=high;i>=low;i-- ){
            string s=to_string(i);
            string k=s;
            reverse(k.begin(),k.end());
             s=s+k;
             cout<<a<<endl;
             long long element=stoll(s);
             for(long long j=high;j*j>=element;j--){
                
                 if(element%j==0){
                     return element%1337;
                 }
                
             }
             
        } 
        
       return -1; 
    }
};