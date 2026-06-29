class Solution {
public:
    bool checkRecord(string s) {
        int absents = 0, lates = 0;
        
        for (char c : s) {
            absents += (c == 'A');
            
            if (c == 'L') {
                lates = lates + 1;
            } else {
                lates = 0;
            }
            
            if (absents >= 2 || lates >= 3) {
                return false;
            }
        }
        
        return true;
    }
};