class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums) {
            int count = 0;
            int sum = 0;
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    if (d * d == x) {
                        count += 1;
                        sum += d;
                    } else {
                        count += 2;
                        sum += d + (x / d);
                    }
                }
                if (count > 4) break;
            }
            if (count == 4) {
                totalSum += sum;
            }
        }
        return totalSum;
    }
};