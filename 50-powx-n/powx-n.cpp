class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1.000;
        }
        
        double ans=1.00;
        vector<int>num;
        
        while(n!=0){
            if(n%2==0){
                num.push_back(n);
                n=n/2;
            }
            else{
                num.push_back(n);
                if(n>0){
                    n-=1;
                }
                else{
                    n+=1;
                }
            }

        }
        reverse(num.begin(),num.end());
        for(auto j:num){
            cout<<ans<<" "<<j<<endl;
            if(j%2==1||j%2==-1){
                if(j>0){
                    ans*=x;
                }
                else{
                    ans/=x;
                }
            }
            else{
                ans*=ans;
            }
        }
        return ans;
    }
};