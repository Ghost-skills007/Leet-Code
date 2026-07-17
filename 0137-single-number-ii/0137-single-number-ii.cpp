class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        
        for (int i = 0; i < 32; ++i) {
            int bit_sum = 0;
            
            for (int num : nums) {
                if ((num >> i) & 1) {
                    bit_sum++;
                }
            }
            
            if (bit_sum % 3 != 0) {
                result |= (1 << i);
            }
        }
        
        return result;
    }
};