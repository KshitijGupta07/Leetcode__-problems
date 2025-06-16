class Solution {
public:
   int solve(vector<int>&prices,int index,int &maxprofit,int &minprice){
    if(index>=prices.size()){
        return 0;
    }
    minprice=min(minprice,prices[index]);
    maxprofit=max(maxprofit,prices[index]-minprice);
    return solve(prices,index+1,maxprofit,minprice);
   }
    int maxProfit(vector<int>& prices) {
        int maxprofit=INT_MIN;
        int minprice=INT_MAX;
        int ans=solve(prices,0,maxprofit,minprice);
        return maxprofit;
    }
};