#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixXOR(n + 1, 0);
        // Compute prefix XOR for quick subarray XOR calculation
        for (int i = 0; i < n; ++i) {
            prefixXOR[i + 1] = prefixXOR[i] ^ nums[i];
        }

        // dp[i][j] = minimum maximum XOR for first i elements split into j parts
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        dp[0][0] = 0;

        // Fill dp table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                // Try all possible previous partition points
                for (int m = j - 1; m < i; ++m) {
                    int currentXOR = prefixXOR[i] ^ prefixXOR[m];
                    int candidate = max(dp[m][j - 1], currentXOR);
                    dp[i][j] = min(dp[i][j], candidate);
                }
            }
        }

        return dp[n][k];
    }
};
