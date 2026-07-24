class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<int> result;
        int count = 1;
        int i = 0;
        
        while (count <= n) {
            if (i < n && nums[i] < count) {
                i++;
            }
            else if (i < n && nums[i] == count) {
                i++;
                count++;
            }
            else {
                result.push_back(count);
                count++;
            }
        }
        
        return result;
    }
};