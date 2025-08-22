class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1000000007LL;

        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            long long mul = v % MOD;

            for (int i = l; i <= r; i += k) {
                long long cur = nums[i] % MOD;
                cur = (cur * mul) % MOD;
                nums[i] = static_cast<int>(cur);
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};
