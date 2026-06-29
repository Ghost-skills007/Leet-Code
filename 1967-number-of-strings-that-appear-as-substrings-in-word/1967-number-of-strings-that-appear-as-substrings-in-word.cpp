class Solution {
public:
    int numOfStrings(std::vector<std::string>& patterns, std::string word) {
        int count = 0;

        for (std::string p : patterns) {
            bool found = false;
            
            if (p.length() <= word.length()) {
                for (int i = 0; i <= word.length() - p.length(); i++) {
                    if (word.substr(i, p.length()) == p) {
                        found = true;
                        break;
                    }
                }
            }
            
            if (found) {
                count++;
            }
        }

        return count;
    }
};