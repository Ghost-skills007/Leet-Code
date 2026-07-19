class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        int onesS = 0;
        for (char c : s) if (c == '1') onesS++;

        vector<bool> ans;

        for (string &t : strs) {
            int fixedOnes = 0, totalQ = 0;
            for (char c : t) {
                if (c == '1') fixedOnes++;
                else if (c == '?') totalQ++;
            }

            int need = onesS - fixedOnes;
            if (need < 0 || need > totalQ) {
                ans.push_back(false);
                continue;
            }

            int prefS = 0, prefFixed = 0, prefQ = 0;
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (s[i] == '1') prefS++;
                if (t[i] == '1') prefFixed++;
                else if (t[i] == '?') prefQ++;

                int low = max(0, need - (totalQ - prefQ));
                if (prefS - prefFixed < low) {
                    ok = false;
                    break;
                }
            }

            ans.push_back(ok);
        }

        return ans;
    }
};