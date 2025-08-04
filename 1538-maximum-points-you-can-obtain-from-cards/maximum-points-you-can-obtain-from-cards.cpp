class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int>prefix;
        
        int sum=0;
        for(int i=0;i<cardPoints.size();i++){
             sum=sum+cardPoints[i];
             prefix.push_back(sum);
        }
        if(k==prefix.size()){
            return prefix.back();
        }
        sum=max(prefix[k-1],prefix.back()-prefix[prefix.size()-k-1]);
        cout<<sum<<endl;
        for(int i=1;i<=k-1;i++){
            int j=k-i;
          sum=max(sum,prefix[i-1]+prefix.back()-prefix[prefix.size()-1-j]);
        }
        return sum;
    }
};