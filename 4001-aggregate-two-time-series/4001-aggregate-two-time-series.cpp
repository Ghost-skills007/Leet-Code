class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
int i = 0, j = 0;
        int n = series1.size(), m = series2.size();
        vector<vector<int>> res;
        
        int val1 = 0, val2 = 0;
        int next1 = n > 0 ? series1[0][1] : 0;
        int next2 = m > 0 ? series2[0][1] : 0;
        
        while (i < n || j < m) {
            if (i < n && (j >= m || series1[i][0] < series2[j][0])) {
                int ts = series1[i][0];
                if (j < m && ts < series2[j][0]) {
                    val2 = next2;
                } else if (j < m && ts == series2[j][0]) {
                    val2 = series2[j][1];
                    j++;
                } else {
                    val2 = 0;
                }
                val1 = series1[i][1];
                i++;
                res.push_back({ts, val1 + val2});
            }
            else if (j < m && (i >= n || series2[j][0] < series1[i][0])) {
                int ts = series2[j][0];
                if (i < n && ts < series1[i][0]) {
                    val1 = next1;
                } else if (i < n && ts == series1[i][0]) {
                    val1 = series1[i][1];
                    i++;
                } else {
                    val1 = 0;
                }
                val2 = series2[j][1];
                j++;
                res.push_back({ts, val1 + val2});
            }
            else {
                int ts = series1[i][0];
                val1 = series1[i][1];
                val2 = series2[j][1];
                i++;
                j++;
                res.push_back({ts, val1 + val2});
            }
            
            next1 = (i < n) ? series1[i][1] : 0;
            next2 = (j < m) ? series2[j][1] : 0;
        }
        
        return res;
    }
};