class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        unordered_set<char> ransomSet(ransomNote.begin(), ransomNote.end());

        for (char c : ransomSet) {
            if (countOccurrences(magazine, c) < countOccurrences(ransomNote, c)) {
                return false;
            }
        }
        return true;
    }

private:
    int countOccurrences(const string& str, char c) {
        return count(str.begin(), str.end(), c);
    }    
};