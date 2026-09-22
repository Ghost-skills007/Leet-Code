namespace {
    template<int N>
    struct Node {
        int cnt[N];
        int ss;

        Node(): cnt{}, ss(1 % N) {}
    };

    template<int N>
    class SegmentTree {
        inline static Node<N> arr[400000];
        int _l;

        void merge(Node<N> &res, const Node<N>& left, const Node<N>& right) {

            res.ss = (1LL * left.ss * right.ss) % N;

            for (int i = 0; i < N; ++i) {
                res.cnt[i] = left.cnt[i];
            }

            for (int i = 0; i < N; ++i) {
                int tmp = (1LL * left.ss * i) % N;
                res.cnt[tmp] += right.cnt[i];
            }
        }

        int build(int p, vector<int> &nums, int tl, int tr) {
            if (tl == tr) {
                int tmp = nums[tl] % N;
                arr[p].cnt[tmp] = 1;
                arr[p].ss = tmp;
                return tmp;
            } else {
                int mid = tl + ((tr - tl) >> 1);
                int a = build(2 * p, nums, tl, mid);
                int b = build(2 * p + 1, nums, mid + 1, tr);

                merge(arr[p], arr[2 * p], arr[2 * p + 1]);
                return arr[p].ss;
            }
        }

        void update(int p, int val, int idx, int tl, int tr) {
            if (tl == tr) {
                int tmp = val % N;
                arr[p] = Node<N>();
                arr[p].cnt[tmp] = 1;
                arr[p].ss = tmp;
                return;
            }

            int mid = tl + ((tr - tl) >> 1);

            if (idx <= mid) {
                update(2 * p, val, idx, tl, mid);
            } else {
                update(2 * p + 1, val, idx, mid + 1, tr);
            }

            merge(arr[p], arr[2 * p], arr[2 * p + 1]);
        }

        Node<N> query(int p, int ql, int qr, int tl, int tr) {
            if (tr < ql || tl > qr) {
                return Node<N>();
            }

            if (ql <= tl && tr <= qr) {
                return arr[p];
            }

            int mid = tl + ((tr - tl) >> 1);

            Node<N> left = query(2 * p, ql, qr, tl, mid);
            Node<N> right = query(2 * p + 1, ql, qr, mid + 1, tr);

            Node res = Node<N>();
            merge(res, left, right);

            return res;
        }

    public:
        SegmentTree(int l, vector<int> &nums): _l(l) {
            fill(arr, arr + 4 * l, Node<N>());
            build(1, nums, 0, l - 1);
        }

        inline void update(int val, int idx) {
            update(1, val, idx, 0, _l - 1);
        }

        inline Node<N> query(int ql, int qr) {
            return query(1, ql, qr, 0, _l - 1);
        }
    };
}

using Seg1 = SegmentTree<1>;
using Seg2 = SegmentTree<2>;
using Seg3 = SegmentTree<3>;
using Seg4 = SegmentTree<4>;
using Seg5 = SegmentTree<5>;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int l = nums.size();
        int ql = queries.size();
        vector<int> ans(ql, 0);

        auto &q = queries[0];
        nums[q[0]] = q[1];
        if (k == 1) {
            
            Seg1 seg = Seg1(l, nums);
            ans[0] = seg.query(q[2], l - 1).cnt[q[3]];
            
            for (int i = 1; i < ql; ++i) {
                ans[i] = hp(seg, queries[i], nums, l);
            }
        } else if (k == 2) {
            Seg2 seg = Seg2(l, nums);
            ans[0] = seg.query(q[2], l - 1).cnt[q[3]];
            
            for (int i = 1; i < ql; ++i) {
                ans[i] = hp(seg, queries[i], nums, l);
            }
        } else if (k == 3) {
            Seg3 seg = Seg3(l, nums);
            ans[0] = seg.query(q[2], l - 1).cnt[q[3]];
            
            for (int i = 1; i < ql; ++i) {
                ans[i] = hp(seg, queries[i], nums, l);
            }
        } else if (k == 4) {
            Seg4 seg = Seg4(l, nums);
            ans[0] = seg.query(q[2], l - 1).cnt[q[3]];
            
            for (int i = 1; i < ql; ++i) {
                ans[i] = hp(seg, queries[i], nums, l);
            }
        } else if (k == 5) {
            Seg5 seg = Seg5(l, nums);
            ans[0] = seg.query(q[2], l - 1).cnt[q[3]];
            
            for (int i = 1; i < ql; ++i) {
                ans[i] = hp(seg, queries[i], nums, l);
            }
        } 

        return ans;
    }
private:

    template<int N>
    inline int hp(SegmentTree<N> &seg, vector<int> const&q, vector<int> &nums, int l) {
        if (nums[q[0]] != q[1]) {
            seg.update(q[1], q[0]);
            nums[q[0]] = q[1];
        }
        return seg.query(q[2], l - 1).cnt[q[3]];
    }
};