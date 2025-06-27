class Solution {
public:
    struct Node {
        Node* link[2];

        Node() {
            link[0] = nullptr;
            link[1] = nullptr;
        }

        bool contain(int bit) {
            return link[bit] != nullptr;
        }

        void put(int bit, Node* node) {
            link[bit] = node;
        }

        Node* get(int bit) {
            return link[bit];
        }
    };

    class Trie {
    public:
        Node* root;

        Trie() {
            root = new Node();
        }

        void insert(int num) {
            Node* node = root;
            for (int i = 30; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (!node->contain(bit)) {
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }

        int getMaxXor(int x) {
            Node* node = root;
            int ans = 0;
            for (int i = 30; i >= 0; --i) {
                int bit = (x >> i) & 1;
                if (node->contain(1 - bit)) {
                    ans |= (1 << i);
                    node = node->get(1 - bit);
                } else if (node->contain(bit)) {
                    node = node->get(bit);
                } else {
                    return -1;
                }
            }
            return ans;
        }
    };

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<tuple<int, int, int>> q;
        for (int i = 0; i < queries.size(); ++i) {
            q.emplace_back(queries[i][0], queries[i][1], i);
        }

        sort(nums.begin(), nums.end());
        sort(q.begin(), q.end(), [](auto& a, auto& b) {
            return get<1>(a) < get<1>(b); // sort by mi
        });

        Trie* trie = new Trie();
        vector<int> ans(queries.size(), -1);
        int j = 0;

        for (const auto& [xi, mi, idx] : q) {
            while (j < nums.size() && nums[j] <= mi) {
                trie->insert(nums[j]);
                ++j;
            }
            if (j == 0) {
                ans[idx] = -1;  // No numbers ≤ mi
            } else {
                ans[idx] = trie->getMaxXor(xi);
            }
        }

        return ans;
    }
};
