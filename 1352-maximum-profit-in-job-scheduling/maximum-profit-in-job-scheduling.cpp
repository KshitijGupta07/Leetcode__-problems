class Solution {
public:

    int binary(vector<vector<int>>&v,int index,vector<int>&dp){
        if(index>=v.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int start=0;
        int end=v.size()-1;
        int ans=v.size();
        while(start<=end){
            int mid=(start+end)/2 ;
            if(v[mid][0]>=v[index][1]){
                 ans=mid;
                 end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        return dp[index]=max(binary(v,index+1,dp),v[index][2]+binary(v,ans,dp));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>v;
        vector<int>dp(startTime.size(),-1);
        for(int i=0;i<startTime.size();i++){
            v.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(v.begin(),v.end());
        int ans=binary(v,0,dp);
        return ans;
    }
};