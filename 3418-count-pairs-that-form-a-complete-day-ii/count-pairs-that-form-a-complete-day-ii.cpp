class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
         unordered_map<int,int>m;
         long long ans=0;
        for(int i=0;i<hours.size();i++){
          
            ans+=m[(24-hours[i]%24)%24];
              m[hours[i]%24]++;
        }
        return ans;
    
    }
};