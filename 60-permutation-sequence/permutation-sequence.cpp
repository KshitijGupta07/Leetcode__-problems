class Solution {
public:
   int factorial(int n){
    if(n==1){
        return 1;
    }
    int product=1;
    for(int i=1;i<=n;i++){
        product*=i;
    }
    return product;
   }
    string getPermutation(int n, int k) {
        string ans="";
        vector<int>fix(n+1,0);
        for(int i=0;i<n+1;i++){
            fix[i]=i;
        }
        n=n-1;
        while(k>0){
        int a=k/factorial(n);
         int b=k%factorial(n);
         int c=a+min(1,b);
          ans.push_back(fix[c]+'0');
          fix.erase(fix.begin()+c);
          k=k-a*factorial(n);
         n-=1;
        }
        fix.erase(fix.begin());
        reverse(fix.begin(),fix.end());
        for(auto j:fix){
            ans.push_back(j+'0');
        }
        return ans;
    }
};