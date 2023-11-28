class Solution {
public:
    int dayOfYear(string date) {
        int day=(date[8]-'0')*10+(date[9]-'0');
        int month=(date[5]-'0')*10+(date[6]-'0');
        int year=(date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0');
        int ans=0;
        if(month<3){
            return (month/2)*31+day;
        }
        else if(month>=3&&month<9){
            ans=(month/2)*31+(month-month/2 -2)*30+day+28;
        }
        else{
            if(month%2==1){
                ans=(month/2 +1)*31+(month-month/2-3)*30+day+28;
            }
            else{
                ans=(month/2 )*31+(month-month/2-2)*30+day+28;
            }
        }
        int a=ans;
        if(year%4==0&&year%100==0&&year%400==0){
            return a+1;
        }
        if(year%4==0&&year%100!=0)return a+1;
        return a;
        
        
    }
};