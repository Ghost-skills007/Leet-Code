class Solution {
public:
    int dp[1001][1001];
    int sum[1001][1001];
    int numberOfSets(int n, int k) {
        int mod = 1000000007;
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));

        for(int i=2; i<=n; i++) {
            for(int j=1; j<=k && j<=i-1; j++) {
                if(j == 1) dp[i][j] = i * (i-1) / 2;
                else dp[i][j] = (dp[i-1][j] + sum[i-1][j-1]) % mod;
                
                sum[i][j] = (sum[i-1][j] + dp[i][j]) % mod;
            }
        }

        return dp[n][k];
    }
};