class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      vector<int> z = {-1};
    for (int i = 0; i < nums.size(); i++) 
        if (!nums[i]) z.push_back(i);
    z.push_back(nums.size());

    if (z.size() - 2 <= k) return nums.size();

    int ans = 0;
    for (int i = 1; i + k < z.size(); i++) 
        ans = max(ans, z[i + k] - z[i - 1] - 1);

    return ans;
    }
};