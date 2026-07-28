class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        for (auto& arr : nums) {
            sort(arr.begin(), arr.end());
        }
        vector<int> result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            vector<int> temp;
            int p1 = 0, p2 = 0;
            while (p1 < result.size() && p2 < nums[i].size()) {
                if (result[p1] == nums[i][p2]) {
                    temp.push_back(result[p1]);
                    p1++;
                    p2++;
                } else if (result[p1] < nums[i][p2]) {
                    p1++;
                } else {
                    p2++;
                }
            }
            result = temp;
            if (result.empty()) break;
        }
        return result;
    }
};