class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        
        string s = to_string(n);
        string x_str = "";
        long long digit_sum = 0;
        
        for (char c : s) {
            if (c != '0') {
                x_str += c;
                digit_sum += (c - '0');
            }
        }
        if (x_str.empty()) return 0;
        
        long long x = stoll(x_str);
        
        return x * digit_sum;

    }
};