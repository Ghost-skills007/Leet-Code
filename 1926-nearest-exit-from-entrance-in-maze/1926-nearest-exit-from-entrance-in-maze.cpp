class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;
        q.emplace(entrance[0], entrance[1]);
        maze[entrance[0]][entrance[1]] = '#';
        int level = 0;

        while (!q.empty()) {
            level++;
            int nodes_left_in_level = q.size();
            while (nodes_left_in_level--) {
                auto [x, y] = q.front(); q.pop();
                int dx[]{0, 0, 1, -1};
                int dy[]{1, -1, 0, 0};
                for (int k = 0; k < 4; k++) {
                    int a = x + dx[k];
                    int b = y + dy[k];
                    if (a < 0 || b < 0 || a >= m || b >= n || maze[a][b] != '.') continue;
                    if (a == 0 || b == 0 || a == m - 1 || b == n - 1) return level;
                    maze[a][b] = '#';
                    q.emplace(a, b);
                }
            }
        }
        return -1;
    }
};