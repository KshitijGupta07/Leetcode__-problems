class Solution {
public:
 int dayOfYear(int day,int month,int year) {
        
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
    string dayOfTheWeek(int day, int month, int year) {
        int numdays=dayOfYear(day,month,year);
        int a=0;
        cout<<numdays<<endl;
        if(year<=2100){
             a=((year-year%4-14)/4)*366+(year-(year-year%4)/4)*365;
            a=a%7;
            a=a+numdays;
        a=a%7;
        
        
        }
        cout<<a<<endl;
        if(year==2100){
            a=a-1;
        }
       cout<<a<<endl;
        if((year%4==0&&year%100==0&&year%400==0)||(year%4==0&&year%100!=0)){
            a=a-1;
        }
         
        cout<<a<<endl;
        if(a==0){
            return "Saturday";
        }
        else if(a==1){
            return "Sunday";
        }
        else if(a==2){
            return "Monday";
        }
        else if(a==3){
            return "Tuesday";
        }
        else if(a==4){
            return "Wednesday";
        }
        else if(a==5){
            return "Thursday";
        }
        return "Friday";
        
      
        
    }
};