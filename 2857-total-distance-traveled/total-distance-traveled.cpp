class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans=0;
        if(mainTank<5){
            return mainTank*10;
        }
        while(mainTank>=5&&additionalTank>=1){
            ans=ans+50;
            mainTank=mainTank-4;
            additionalTank--;
        }
        cout<<mainTank<<" "<<additionalTank ;
        return ans+mainTank*10;
        
    }
};