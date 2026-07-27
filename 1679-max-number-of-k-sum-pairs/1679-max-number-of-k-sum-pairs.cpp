class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1, ans = 0;

while (l < r) {
    int sum = nums[l] + nums[r];
    if (sum == k) { ans++; l++; r--; }
    else if (sum < k) l++;
    else r--;
}
return ans;
    }
};