class Solution {
public:
    int findMin(vector<int>& nums) {
        auto min_it = min_element(nums.begin(), nums.end());
        return *min_it;
    }
};
