class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5=0;
        int count10=0;
        int count20=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                count5++;
            }
            else{
                if(bills[i]==10){
                    if(count5==0){
                          return false;
                    }
                    else{
                        count5=count5-1;
                        count10++;
                    }
                }
                if(bills[i]==20){
                    if(count5==0){
                        return false;
                    }
                    else if(count10==0){
                        if(count5<3){
                        return false;
                        }
                        else{
                            count5=count5-3;
                        }
                    }
                    else{
                        count5=count5-1;
                        count10=count10-1;
                        count20++;
                    }
                }
            }
        }
        return true;
    }
};