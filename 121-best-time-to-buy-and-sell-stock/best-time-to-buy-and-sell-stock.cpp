class Solution {
public:
    void badaprofit(vector<int>& prices,int& minprice,int& maxprofit,int i){    if(i==prices.size()){
        return;
    }
       if(prices[i]<minprice) minprice=prices[i];
       if(prices[i]-minprice>maxprofit) maxprofit=prices[i]-minprice;
       badaprofit(prices,minprice,maxprofit,i+1);
    }
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;
        int maxprofit=INT_MIN;
        badaprofit(prices,minprice,maxprofit,0);
        return maxprofit;

    }
};