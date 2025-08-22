class Solution {
    static constexpr int MOD = 1000000007;

    static long long modPow(long long a, long long e) {
        long long r = 1;
        while (e > 0) {
            if (e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }

public:
    int xorAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        const int n = (int)nums.size();

        // F[i] will store the combined multiplicative factor for position i
        std::vector<long long> F(n, 1);

        // Group queries by k, then by residue (l % k)
        // Using vector of unordered_maps keeps memory bounded and cache-friendly.
        std::vector<std::unordered_map<int, std::vector<std::array<int,3>>>> byK(n + 1);
        byK.shrink_to_fit();

        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            int res = l % k;
            byK[k][res].push_back({l, r, v});
        }

        // Optional: cache inverses of v to avoid repeated pow calls
        std::unordered_map<int, int> invCache;
        invCache.reserve(1 << 15);

        auto getInv = [&](int v) -> int {
            auto it = invCache.find(v);
            if (it != invCache.end()) return it->second;
            int inv = (int)modPow(v % MOD, MOD - 2);
            invCache.emplace(v, inv);
            return inv;
        };

        // Process per k to keep memory peak ~ O(n)
        for (int k = 1; k <= n; ++k) {
            if (byK[k].empty()) continue;

            for (auto& [res, vec] : byK[k]) {
                // subsequence positions: res, res+k, res+2k, ...
                // T = number of terms in this residue class within [0, n-1]
                int T = (n - 1 - res >= 0) ? ((n - 1 - res) / k + 1) : 0;
                if (T <= 0) continue;

                // multiplicative difference array on the compact index line
                std::vector<long long> diff(T + 1, 1);

                for (const auto& qr : vec) {
                    int l = qr[0], r = qr[1], v = qr[2];
                    // Map l and r to compact indices tL, tR on this residue line
                    // Since res = l % k, both l and the first hit share this residue.
                    int tL = (l - res) / k;
                    int tR = (r - res) / k;
                    if (tL < 0) tL = 0;
                    if (tR >= T) tR = T - 1;
                    if (tL > tR) continue;

                    diff[tL] = (diff[tL] * (v % MOD)) % MOD;
                    long long inv = getInv(v);
                    diff[tR + 1] = (diff[tR + 1] * inv) % MOD;
                }

                // Prefix product to recover actual factor per element in this residue class
                long long cur = 1;
                for (int t = 0; t < T; ++t) {
                    cur = (cur * diff[t]) % MOD;
                    int pos = res + t * k;
                    F[pos] = (F[pos] * cur) % MOD;
                }
            }
        }

        // Build the final XOR
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            long long val = ( (long long)(nums[i] % MOD) * F[i] ) % MOD;
            ans ^= (int)val;
        }
        return ans;
    }
};
