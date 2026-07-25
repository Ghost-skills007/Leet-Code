class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    long long maxNum = nums.back();
    int count = 1;
    int ptr = 0;
    int n = nums.size();
    while (count <= maxNum + 1) {
        while (ptr < n && nums[ptr] < count) {
            ptr++;
        }
        
        if (ptr < n && nums[ptr] == count) {
            count++;
        } else {
            return count;
        }
    } 
    return count;
    }
};