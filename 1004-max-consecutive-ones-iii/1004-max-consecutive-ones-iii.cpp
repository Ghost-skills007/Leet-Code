class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
    vector<int> zero_indices;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            zero_indices.push_back(i);
        }
    }

    int total_zeroes = zero_indices.size();

    if (total_zeroes <= k) {
        return n;
    }

    int max_len = 0;

    for (int i = 0; i <= total_zeroes - k; i++) {
        int left_boundary = (i == 0) ? 0 : zero_indices[i - 1] + 1;
        int right_boundary = (i + k == total_zeroes) ? n - 1 : zero_indices[i + k] - 1;

        int current_length = right_boundary - left_boundary + 1;
        max_len = max(max_len, current_length);
    }

    return max_len;
    }
};