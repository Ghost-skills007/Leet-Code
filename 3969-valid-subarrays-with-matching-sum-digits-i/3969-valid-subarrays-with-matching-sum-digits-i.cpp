class Solution {
private:
    bool isValidSum(long long sum, int x) {
        if (sum % 10 != x) return false;
        
        long long temp = sum;
        while (temp >= 10) {
            temp /= 10;
        }
        
        return temp == x;
    }

public:
    int countValidSubarrays(std::vector<int>& nums, int x) {
        int n = nums.size();
        int valid_count = 0;
        
        for (int i = 0; i < n; ++i) {
            long long current_sum = 0;
            
            for (int j = i; j < n; ++j) {
                current_sum += nums[j];
                
                if (isValidSum(current_sum, x)) {
                    valid_count++;
                }
            }
        }
        
        return valid_count;
    }
};