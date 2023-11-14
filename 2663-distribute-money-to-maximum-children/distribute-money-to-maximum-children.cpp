class Solution {
public:
    int distMoney(int money, int children) {
        if(money/children<1){
            return -1;
        }
        int count=0;
        vector<int>v(children,1);
        money=money-children;
        for(int i=0;i<children-1;i++){
            if(money>6){
            v[i]+=7;
            money-=7;
            count++;
        }
        }
        if(money==7){
            count++;
        }
        if(money==3){
            if(v[children-2]==8)count--;
            
        }
        return count;
    }
};