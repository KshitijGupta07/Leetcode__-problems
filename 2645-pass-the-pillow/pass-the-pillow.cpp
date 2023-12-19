class Solution {
public:
    int passThePillow(int n, int time) {
        if(time>n){
            int a=time/(n-1);
            time=time-a*(n-1);
            cout<<time<<endl;
            if(a%2==0){
                return time +1;
            }
            else{
                return n-time;
            }
        }
        if(time==n){
            return n-1;
        }
        return time +1;
        
    }
};