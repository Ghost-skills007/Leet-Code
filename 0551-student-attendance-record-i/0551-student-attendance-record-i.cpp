class Solution {
public:
    bool checkRecord(string s) {
        int absents = 0, lates = 0;
        for (char c : s) {
            absents += (c == 'A');
            lates = (c == 'L') ? lates + 1 : 0;
            
            if (absents >= 2 || lates >= 3) return false;
        }
        return true;
    }
};