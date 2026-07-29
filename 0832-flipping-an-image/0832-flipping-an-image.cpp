class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto &i : image) {
            for (auto &j : i) {
                j = 1-j;
            }
            reverse(i.begin(), i.end());
        }
        return image;
    }
};