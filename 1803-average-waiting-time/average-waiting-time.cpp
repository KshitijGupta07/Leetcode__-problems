class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long  currenttime=0;
        long long  waitingtime=0;
        long long n=customers.size();
        for(int i=0;i<customers.size();i++){
                 if(i==0){
                    currenttime=currenttime+customers[0][0]+customers[0][1];
                    waitingtime=currenttime-customers[0][0];
                 }
                 
               else if(currenttime>customers[i][0]&&i>0){
                    waitingtime+=currenttime-customers[i][0]+customers[i][1];
                     currenttime+=customers[i][1];
                }
                else if(currenttime<=customers[i][0]){
                    waitingtime+=customers[i][1];
                    currenttime=customers[i][0];
                    currenttime+=customers[i][1];
                }
            
        }
        double w=waitingtime;
        double c=n;
      double a=w/c;
      return a;
    }
};