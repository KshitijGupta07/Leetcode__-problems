class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxi=difficulty[0];
        for(int i=1;i<difficulty.size();i++){
            maxi=max(maxi,difficulty[i]);
        }
        vector<int>maxprofit(maxi+1,0);
        for(int i=0;i<difficulty.size();i++){
            maxprofit[difficulty[i]]=max(maxprofit[difficulty[i]],profit[i]);
        }
        for(int i=1;i<maxprofit.size();i++){
            maxprofit[i]=max(maxprofit[i],maxprofit[i-1]);
        }
        int sum=0;
        for(int i=0;i<worker.size();i++){
            if(worker[i]>maxi){
                sum+=maxprofit[maxi];
            }
            else{
                sum+=maxprofit[worker[i]];
            }
        }
        return sum;
    }
};