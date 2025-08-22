class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        const long long INF = (1LL << 62);
        // best[r] = minimum dp[j] among positions j seen with pref[j] == r
        std::vector<long long> best(k, INF);

        long long dp = 0;           // dp[0]
        int rem = 0;                // pref[0] % k
        best[rem] = 0;

        for (int x : nums) {
            rem += x % k;           // update prefix remainder
            if (rem >= k) rem -= k; // avoid slow modulo; nums[i] >= 1

            long long keep = dp + x;               // keep this element
            long long jump = best[rem];            // delete a block to here
            long long cur = std::min(keep, jump);  // dp for next position

            // make this position available for future jumps
            if (cur < best[rem]) best[rem] = cur;

            dp = cur;
        }
        return dp;
    }
};
