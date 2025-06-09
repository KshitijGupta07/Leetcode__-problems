class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;

        int maxi =0;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
            int m = mp[nums[i]].size();
            maxi = max(maxi, m);
        }

        int ans = INT_MAX;

        for(auto it : mp){
            if(it.second.size() == maxi){
                ans = min(ans, it.second.back() - it.second[0] + 1);
            }
        }

        return ans;

    }
};