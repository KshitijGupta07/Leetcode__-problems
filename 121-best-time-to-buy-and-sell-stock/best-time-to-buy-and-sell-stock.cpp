class Solution {
public:
    int solve(int &minprice,int &maxprofit,vector<int>&prices,int i){
        if(i==prices.size()){
            return 0;
        }
        if(prices[i]<minprice){
            minprice=prices[i];
        }
        if(prices[i]-minprice>maxprofit){
            maxprofit=prices[i]-minprice;
        }
        return solve(minprice,maxprofit,prices,i+1);
    }
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;
        int maxprofit=INT_MIN;
        int ans=solve(minprice,maxprofit,prices,0);
        return maxprofit;
    }
};