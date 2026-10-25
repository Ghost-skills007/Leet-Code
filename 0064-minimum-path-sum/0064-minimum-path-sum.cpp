class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1) continue;
                int rightMin = (j + 1 >= n)? INT_MAX : grid[i][j + 1]; //
                int downMin = (i + 1 >= m)? INT_MAX : grid[i + 1][j];
                grid[i][j] = grid[i][j] + (min(rightMin, downMin)); 
            }
        }
        return grid[0][0];
        
    }
};