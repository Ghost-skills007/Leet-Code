class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1000000007LL;
        int n = nums.size();

        vector<long long> cnt(4 * n, 0);
        vector<long long> sq(4 * n, 0);
        vector<long long> lazy(4 * n, 0);
        unordered_map<int, int> last;

        auto apply = [&](int node, int l, int r, long long v) {
            long long len = r - l + 1;
            sq[node] = (sq[node] + 2 * v * cnt[node] + len * v * v) % MOD;
            cnt[node] = (cnt[node] + len * v) % MOD;
            lazy[node] += v;
        };

        auto update = [&](auto&& self, int node, int l, int r,
                          int ql, int qr) -> void {
            if (ql <= l && r <= qr) {
                apply(node, l, r, 1);
                return;
            }

            int mid = (l + r) / 2;
            int lc = node * 2;
            int rc = lc + 1;

            if (lazy[node]) {
                apply(lc, l, mid, lazy[node]);
                apply(rc, mid + 1, r, lazy[node]);
                lazy[node] = 0;
            }

            if (ql <= mid)
                self(self, lc, l, mid, ql, qr);

            if (qr > mid)
                self(self, rc, mid + 1, r, ql, qr);

            cnt[node] = (cnt[lc] + cnt[rc]) % MOD;
            sq[node] = (sq[lc] + sq[rc]) % MOD;
        };

        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            int l = last.count(nums[i]) ? last[nums[i]] + 1 : 0;
            last[nums[i]] = i;

            update(update, 1, 0, n - 1, l, i);
            ans = (ans + sq[1]) % MOD;
        }

        return static_cast<int>(ans);
    }
};