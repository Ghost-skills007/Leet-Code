class Solution {
public:
    string digitSum(string s, int k) {

        while (s.size() > k) {
            string temp = "";
            int i = 0;
            while (i < s.size()) {
                int repeat = k;
                int sum = 0;
                while (i < s.size() && repeat--) {
                    sum += s[i] - '0';
                    i++;
                }
                string k = to_string(sum);
                temp += k;
            }
            s = temp;
        }
        return s;
    }
};