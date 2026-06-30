class Solution {
public:
    int shortestPath(int n, std::vector<std::vector<int>>& edges, std::string labels, int k) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        const int INF = 1e9;
        std::vector<std::vector<int>> dist(n, std::vector<int>(k + 1, INF));

        std::priority_queue<std::tuple<int, int, int>, 
                            std::vector<std::tuple<int, int, int>>, 
                            std::greater<std::tuple<int, int, int>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (u == n - 1) {
                return d;
            }

            if (d > dist[u][count]) {
                continue;
            }

            for (const auto& [v, weight] : adj[u]) {
                int next_count = (labels[v] == labels[u]) ? count + 1 : 1;

                if (next_count <= k) {
                    if (d + weight < dist[v][next_count]) {
                        dist[v][next_count] = d + weight;
                        pq.push({dist[v][next_count], v, next_count});
                    }
                }
            }
        }

        return -1;
    }
};