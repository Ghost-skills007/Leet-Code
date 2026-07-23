class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();

        int i = 0;
        int j = n - 1;

        auto isVowel = [&](char c) -> bool {
            c = tolower(c);

            return c == 'a' || c == 'e' ||
                   c == 'i' || c == 'o' ||
                   c == 'u';
        };

        while(i < j) {

            while(i < j && !isVowel(s[i]))
                i++;

            while(i < j && !isVowel(s[j]))
                j--;

            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};
