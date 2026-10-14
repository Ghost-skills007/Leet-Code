class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }

        int n = nums.size();
        int left = 0;
        int window = 1;
        int count = 0;

        for (int i = 0; i < n; i++) {
            window *= nums[i];

            while (window >= k) {
                window /= nums[left];
                left++;
            }

            count += i - left + 1;
        }

        return count;
    }
};