class Solution {
public:
    vector<int> buildZ(string &s) {
        int n = s.size();
        vector<int> Z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) {
                Z[i] = min(r - i, Z[i - l]);
            }
            while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
                Z[i]++;
            }
            if (i + Z[i] > r) {
                l = i;
                r = i + Z[i];
            }
        }
        return Z;
    }
    int minStartingIndex(string s, string pattern) {
        int n = s.size(), m = pattern.size();
        if (m > n) return -1;

        string front = pattern + "?" + s;
        reverse(s.begin(), s.end());
        reverse(pattern.begin(), pattern.end());
        string back = pattern + "?" + s;

        vector<int> zfront = buildZ(front);
        vector<int> zback = buildZ(back);

        for (int i = 0; i < n; i++) {
            if (n < m + i) break;
            if (m - zfront[i + m + 1] - zback[n - i + 1] <= 1) return i;
        }
        return -1;
    }
};