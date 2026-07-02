class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> foundNumbers;
        int n = digits.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || i == k || j == k) continue;

                    int h = digits[i];
                    int t = digits[j];
                    int o = digits[k];

                    if (h == 0) continue;
                    if (o % 2 != 0) continue;

                    int num = h * 100 + t * 10 + o;
                    foundNumbers.insert(num);
                }
            }
        }

        return foundNumbers.size();
    }
};