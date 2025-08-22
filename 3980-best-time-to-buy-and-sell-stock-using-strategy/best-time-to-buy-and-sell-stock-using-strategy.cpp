class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int m = k / 2;

        // Original profit
        long long orig = 0;
        for (int i = 0; i < n; ++i) orig += 1LL * strategy[i] * prices[i];

        // Precompute A[i] and B[i]
        vector<long long> preA(n + 1, 0), preB(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            long long A = -1LL * strategy[i] * prices[i];           // first half -> 0
            long long B = 1LL * prices[i] - 1LL * strategy[i] * prices[i]; // second half -> 1
            preA[i + 1] = preA[i] + A;
            preB[i + 1] = preB[i] + B;
        }

        long long best = orig; // no modification
        for (int l = 0; l + k <= n; ++l) {
            int mid = l + m;
            int r = l + k;
            long long delta =
                (preA[mid] - preA[l]) +   // first half -> 0
                (preB[r] - preB[mid]);    // second half -> 1
            best = max(best, orig + delta);
        }

        return best;
    }
};
