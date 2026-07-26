class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        int left = 0, right = words.size() - 1;
        while (left < right) {
            swap(words[left], words[right]);
            left++;
            right--;
        }
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) {
                result += " ";
            }
        }
        return result;
    }
};