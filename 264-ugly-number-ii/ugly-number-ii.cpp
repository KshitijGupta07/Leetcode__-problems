class Solution {
public:
    void solve(long long val,set<long long>&m){
        if(val>INT_MAX){
            return;
        }
        
        if(m.find(val)!=m.end()){
            return;
        }
        
        m.insert(val);
        solve(2*val,m);
        solve(3*val,m);
        solve(5*val,m);
        

    }
    int nthUglyNumber(int n) {
        set<long long>m;
        
        int val=1;
        solve(val,m);
        int count=1;
        if(n==1){
            return 1;
        }
        for(auto j:m){
           if(count==n){
            return j;
           }
           count++;
        }
        return 1;
    }
};