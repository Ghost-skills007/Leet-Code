class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
    
    long long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        long long num = 1, den = 1;
        for (int i = 0; i < r; i++) {
            num = (num * (n - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }
        return (num * modpow(den, MOD - 2)) % MOD;
    }
    
    int countValidSequences(int n, int k) {
        long long total = comb(n - 1, k - 1);
        long long odd_ways = 0;
        if ((n - k) % 2 == 0) {
            odd_ways = comb((n + k - 2) / 2, k - 1);
        }
        return (total - odd_ways + MOD) % MOD;
    }
};