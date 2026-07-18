class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, max_len = 0;
        int n = s.length();
        
        auto expand_around_center = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1;
        };
        
        for (int i = 0; i < n; i++) {
            int len1 = expand_around_center(i, i);
            int len2 = expand_around_center(i, i + 1);
            int len = max(len1, len2);
            
            if (len > max_len) {
                max_len = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, max_len);
    }
};