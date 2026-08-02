class Solution {
    map<tuple<int,int,int,int,int>, pair<int,int>> dp;
    vector<int> a;

    pair<int,int> solve(int i, int f0, int f1, int w0, int w1) {
        if (i == a.size()) return {0, 0};

        auto key = make_tuple(i, f0, f1, w0, w1);
        if (dp.count(key)) return dp[key];

        int take0 = 0, take1 = 0;
        int wait0 = 0, wait1 = 0;
        int d = a[i];

        if (f0 >= d) {
            auto p = solve(i + 1, f0 - d, f1, d, max(0, w1 - w0));
            take0 = p.first + 1;
            wait0 = max(p.second, w0);
        }

        if (f1 >= d) {
            auto p = solve(i + 1, f0, f1 - d, max(0, w0 - w1), d);
            take1 = p.first + 1;
            wait1 = max(p.second, w1);
        }

        if (take0 > take1) return dp[key] = {take0, wait0};
        if (take1 > take0) return dp[key] = {take1, wait1};
        return dp[key] = {take0, min(wait0, wait1)};
    }

public:
    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        a = demand;
        dp.clear();
        auto ans = solve(0, fuel[0], fuel[1], 0, 0);
        return ans.first ? ans.second : -1;
    }
};