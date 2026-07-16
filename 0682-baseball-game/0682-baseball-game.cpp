class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;

        for (int i = 0; i < operations.size(); i++) {
            int n = ans.size() - 1;

            if (operations[i] == "+") {
                int sum = ans[n] + ans[n - 1];
                ans.push_back(sum);
            }
            else if (operations[i] == "D") {
                ans.push_back(ans[n] * 2);
            }
            else if (operations[i] == "C") {
                ans.pop_back();
            }
            else {
                int number = stoi(operations[i]);
                ans.push_back(number);
            }
        }

        int sum = 0;

        for (int x : ans) {
            sum += x;
        }

        return sum;
    }
};
