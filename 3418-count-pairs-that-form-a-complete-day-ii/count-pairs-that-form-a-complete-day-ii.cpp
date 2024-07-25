class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans=0;
        map<long long ,long long>m;
        for(int i=0;i<hours.size();i++){
            ans+=m[(24-hours[i]%24)%24];
            m[hours[i]%24]++;
        }
        return ans;
    }
};