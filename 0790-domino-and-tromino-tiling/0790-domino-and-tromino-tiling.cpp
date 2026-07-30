class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        long long mod = 1e9 + 7;
        long long prev3 = 1; 
        long long prev2 = 2; 
        long long prev1 = 5; 
        long long current = 0;

        for (int i = 4; i <= n; i++) {
            current = (2 * prev1 + prev3) % mod;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};