class Solution {
public:

    int solve(int prev, int i, vector<vector<int>>& env, vector<vector<int>>& dp) {

        if (i == env.size()) {
            return 0;
        }

        if (dp[i][prev+1] != -1) {
            return dp[i][prev+1];
        }
        int skip = solve(prev, i+1, env, dp);
        int take = 0;

        if (prev == -1 || (env[i][0] > env[prev][0] && env[i][1] > env[prev][1])) {
            take = 1 + solve(i, i+1, env, dp);
        }

        return dp[i][prev+1] = max(take, skip);
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(begin(envelopes), end(envelopes), [&](auto& a, auto& b) {

            if (a[0] == b[0]) {
                return a[1] > b[1];
            }

            return a[0] < b[0];
        });

        vector<int> sortedHeights;

        auto bs = [&](int target) {

            int low = 0;
            int high = sortedHeights.size() - 1;
            int ans = sortedHeights.size();

            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (sortedHeights[mid] >= target) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return low;
        };
        for (auto& env : envelopes) {
            int h = env[1];

            int idx = bs(h);
            if (idx == sortedHeights.size()) {
                sortedHeights.push_back(h);
            } else {
                sortedHeights[idx] = h;
            }
        }

        return sortedHeights.size();
    }
};