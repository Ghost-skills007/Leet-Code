#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

class Solution
{
public:
    vector<long long> resultArray(vector<int> &nums, int k)
    {
        lli n = nums.size();
        vector<vector<lli>> dp(n + 1, vector<lli>(k, 0));
        vector<lli> ans(k, 0);
        int t = nums[0] % k;
        dp[0][t]++;
        ans[t]++;
        for(int i=1;i<n;i++)
        {
            int t = nums[i] % k;
            for(int j=0;j<k;j++) if (dp[i - 1][j] > 0) dp[i][(j * t) % k] += dp[i - 1][j];
            dp[i][t]++;
            for(int j=0;j<k;j++) ans[j] += dp[i][j];
        }
        return ans;
    }
};