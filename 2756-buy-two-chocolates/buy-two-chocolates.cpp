class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
       sort(prices.begin(),prices.end());
       
       int start=0;
       
       int end=prices.size()-1;
       
       
       if(money>prices[0]+prices[1]){
           return money-prices[0]-prices[1];
       }
       if(money==prices[0]+prices[1]){
           return 0;
       }
       return money;

    }
};