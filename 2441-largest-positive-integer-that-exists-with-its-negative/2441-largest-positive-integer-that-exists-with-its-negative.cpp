class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] > 0) {
            int target = -nums[i];
            if (find(nums.begin(), nums.end(), target) != nums.end()) {
                return nums[i];
            }
        } else {
            break;
        }
    }
    return -1;
    }
};