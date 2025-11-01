#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto &f : flights) {
            int u = f[0], v = f[1], w = f[2];
            graph[u].push_back({v, w});
        }

        // dist[node][stops] = best cost to reach `node` using exactly `stops` stops
        // we need stops up to k+1 states (0..k)
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        // min-heap of (cost, node, stops)
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            // If we popped a state that's already worse than stored, skip it
            if (cost > dist[node][stops]) continue;

            // If reached destination, this is the cheapest reachable cost (PQ is ordered by cost)
            if (node == dst) return cost;

            // can't take more flights if we've already used k stops (i.e., k+1 edges)
            if (stops > k) continue;

            for (auto [next, price] : graph[node]) {
                int newCost = cost + price;
                int nextStops = stops + 1;
                if (nextStops <= k + 1 && newCost < dist[next][nextStops]) {
                    dist[next][nextStops] = newCost;
                    pq.push({newCost, next, nextStops});
                }
            }
        }

        // take the minimum cost among all ways to reach dst using <= k+1 flights (i.e., <= k stops)
        int ans = INT_MAX;
        for (int s = 0; s <= k + 1; ++s) ans = min(ans, dist[dst][s]);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
