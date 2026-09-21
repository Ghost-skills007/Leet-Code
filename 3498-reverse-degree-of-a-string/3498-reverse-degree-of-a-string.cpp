class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++){
            int c = 26 - (s[i] - 'a');
            ans += c * (i + 1);
        }
        return ans;
    }
};