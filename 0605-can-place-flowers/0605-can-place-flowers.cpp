class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int count = 0;
        int size = flowerbed.size();

        if (n == 0) return true;
        if (size == 1) {
            return (flowerbed[0] == 0 && n <= 1);
        }

        int i = 0;
        int j = 1;

        while (j < size) {
            if (i == 0 && flowerbed[i] == 0 && flowerbed[j] == 0) {
                flowerbed[i] = 1;
                count++;
            } else if (flowerbed[i] == 0 && flowerbed[j] == 0) {
                if (i - 1 >= 0 && flowerbed[i - 1] == 0) {
                    flowerbed[i] = 1;
                    count++;
                }
            }

            i++;
            j++;
        }

        if (flowerbed[size - 1] == 0 && flowerbed[size - 2] == 0) {
            flowerbed[size - 1] = 1;
            count++;
        }

        return count >= n;
    }
};