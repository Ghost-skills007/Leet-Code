class Solution {
public:
    int maxDistance(std::string moves) {
        int x = 0;
        int y = 0;
        int wildcards = 0;
        
        // Track fixed coordinate changes and count underscores
        for (char move : moves) {
            if (move == 'U') {
                y++;
            } else if (move == 'D') {
                y--;
            } else if (move == 'R') {
                x++;
            } else if (move == 'L') {
                x--;
            } else if (move == '_') {
                wildcards++;
            }
        }
        
        // Maximum Manhattan distance is the base distance plus all wildcards
        return std::abs(x) + std::abs(y) + wildcards;
    }
};