#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMax = nums[0];
        int currentMin = nums[0];
        int finalResult = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int currentNumber = nums[i];

            if (currentNumber < 0) {
                swap(currentMax, currentMin);
            }

            int option1 = currentNumber;
            int option2 = currentMax * currentNumber;
            currentMax = max(option1, option2);

            int option3 = currentMin * currentNumber;
            currentMin = min(option1, option3);

            if (currentMax > finalResult) {
                finalResult = currentMax;
            }
        }

        return finalResult;
    }
};