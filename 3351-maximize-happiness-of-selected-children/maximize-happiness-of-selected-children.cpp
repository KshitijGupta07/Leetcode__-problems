class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long sum=0;
        sum+=happiness[happiness.size()-1];
        happiness.pop_back();
        long long  count=1;
        while(count!=k&&happiness.size()>0){
     
          if(happiness[happiness.size()-1]-count<=0){
            sum+=0;
          }
          else{
            
            long long a=happiness[happiness.size()-1];
               
           sum+=a-count;
           
          }
          count++;
                  happiness.pop_back();
          
        }
        return sum;
    }
};