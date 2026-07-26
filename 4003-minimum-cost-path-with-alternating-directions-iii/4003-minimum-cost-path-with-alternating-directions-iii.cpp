class Solution {
public:
     long long minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<long long> d(m * n * 2, LLONG_MAX / 2);
        priority_queue<array<long long, 4>, vector<array<long long, 4>>, greater<array<long long, 4>>> q;
        q.push({1LL, 0, 0, 0});
        int dirs[4][3] = {{0, 1, 0}, {1, 0, 0}, {0, -1, 1}, {-1, 0, 1}};

        while (!q.empty()) {
            auto [w, i, j, p] = q.top();
            q.pop();

            if (i == m - 1 && j == n - 1) return w;
            if (w > d[(i * n + j) * 2 + p]) continue;

            int k = (i * n + j) * 2 + (p ^ 1);
            if (w + penalty[i][j] < d[k]) {
                d[k] = w + penalty[i][j];
                q.push({w + penalty[i][j], i, j, (long long)(p ^ 1)});
            }

            for (auto& dir : dirs) {
                int dr = dir[0], dc = dir[1], rp = dir[2];
                long long x = i + dr, y = j + dc;
                if (0 <= x && x < m && 0 <= y && y < n) {
                    long long w2 = w + (x + 1) * (y + 1) + (p == rp ? 0 : penalty[i][j]);
                    int next_k = (x * n + y) * 2 + (p ^ 1);
                    if (w2 < d[next_k]) {
                        d[next_k] = w2;
                        q.push({w2, x, y, (long long)(p ^ 1)});
                    }
                }
            }
        }
        return -1;
    }
};