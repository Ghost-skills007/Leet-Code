class Solution {
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    int r, c;
    bool validity(int i, int j) { return i >= 0 && i < r && j >= 0 && j < c; }

    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int timer = 0;
        while (!q.empty()) {
            timer++;
            int curr = q.size();
            while (curr--) {
                int ni = q.front().first;
                int nj = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    if (validity(ni + row[k], nj + col[k]) &&
                        grid[ni + row[k]][nj + col[k]] == 1) {
                        grid[ni + row[k]][nj + col[k]] = 2;
                        q.push({ni + row[k], nj + col[k]});
                    }
                }
            }
        }
        bool what = true;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1)
                    return -1;
                if (grid[i][j] != 0 && grid[i][j] != 1)
                    what = false;
            }
        }

        if (what == true)
            return 0;

        return timer - 1;
    }
};