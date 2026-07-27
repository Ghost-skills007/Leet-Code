class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int count = 0, size = flowerbed.size();
        
        for (int i = 0, j = 1; i < size; i++, j++) {
            if (flowerbed[i] == 0) {
                bool left = (i == 0 || flowerbed[i - 1] == 0);
                bool right = (j >= size || flowerbed[j] == 0);
                
                if (left && right) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        
        return count >= n;
    }
};