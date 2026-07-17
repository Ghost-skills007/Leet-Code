class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int count[32] = {0};
        
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                if ((num >> i) & 1) {
                    count[i]++;
                }
            }
        }
        
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            if (count[i] % 3 != 0) {
                result |= (1 << i);
            }
        }
        
        return result;
    }
};