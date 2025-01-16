class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n);
        for(int i=0;i<bookings.size();i++){
            int a=bookings[i][0]-1;
            int b=bookings[i][1]-1;
            ans[a]+=bookings[i][2];
            if(b+1<n){
                ans[b+1]-=bookings[i][2];
            }
    
        }
        for(int i=1;i<n;i++){
           ans[i]+=ans[i-1];
        }
        return ans;
    }
};