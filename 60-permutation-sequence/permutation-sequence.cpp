class Solution {
public:
   int factorial(int a){
    if(a==0){
        return 1;
    }
   int ans=1;
    for(int j=1;j<=a;j++){
        ans*=j;
    }
    return ans;
   }
    string getPermutation(int n, int k) {
        int i=0;
        string ans="";
        map<int,int>m;
        for(int i=1;i<=n;i++){
            m[i]=1;

        }
        vector<int>c;
        while(k>0){
            
            int a=factorial(n-1);
            int count=1;
            while(a*count<k){
                count++;
            }
            c.push_back(count);
            if(a*count==k){
            k-=(count)*(a);
            }
            else{
                k-=(count-1)*(a);
            }

            n-=1;
        }
        for(int i=0;i<c.size();i++){
               int x=c[i];
             for(auto j:m){
                x-=1;
                if(x==0){
                    ans.push_back(j.first+'0');
                    m.erase(j.first);
                    break;
                }
             }
        }
        string ans2="";
        for(auto j:m){
               ans2.push_back(j.first+'0');

        }
          reverse(ans2.begin(),ans2.end());
            
        
        return ans+ans2;
    }
};