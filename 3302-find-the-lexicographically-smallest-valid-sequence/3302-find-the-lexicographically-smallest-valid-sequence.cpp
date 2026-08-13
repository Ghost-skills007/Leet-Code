class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> rightMatch(n, -1);
        
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                rightMatch[j] = i;
                j--;
            }
            i--;}   
        vector<int> res;
        i = 0; 
        j = 0;
        bool changed = false;
        
        while (i < m && j < n) {
            if (word1[i] == word2[j]) {
                res.push_back(i);
                j++;
            } else if (!changed && (j == n - 1 || rightMatch[j + 1] > i)) {
                changed = true;
                res.push_back(i);
                j++;
            }  i++;
        }
        return j == n ? res : vector<int>{};
    }
};