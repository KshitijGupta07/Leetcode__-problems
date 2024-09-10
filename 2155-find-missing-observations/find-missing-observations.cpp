class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int totalsum=(n+rolls.size())*mean;
       int sum=0;
       for(auto j:rolls){
        sum+=j;
       }
       if(totalsum-sum>6*n||totalsum-sum<0){
        return {};
       }
       vector<int>ans;
       for(int i=0;i<n;i++){
        ans.push_back((totalsum-sum)/n);
       }
       if((totalsum-sum)%n==0){
        return ans;
       }
       int a=(totalsum-sum)%n;
       for(int i=0;i<a;i++){
        ans[i]+=1;
       }
       for(auto j:ans){
        if(j>6||j<=0){
            return {};
        }
       }
       return ans;

    }
};