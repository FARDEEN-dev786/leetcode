class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> a(n);
        for (int i = 0; i < roads.size(); i++) {
            int s = roads[i][0];
            int d = roads[i][1];
            int w = roads[i][2];
            a[s].push_back({d, w});
            a[d].push_back({s, w});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        const int MOD = 1e9 + 7;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            pair<long long, int> p = pq.top();
            pq.pop();
            long long d = p.first;
            int node = p.second;
            if (d > dist[node])
                continue;
            for (int j = 0; j < a[node].size(); j++) {
                int neigh = a[node][j].first;
                int wt = a[node][j].second;
                if (d + wt < dist[neigh]) {
                    dist[neigh] = wt + d;
                    ways[neigh] = ways[node];
                    pq.push({d + wt, neigh});
                } else if (d + wt == dist[neigh]) {
                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};