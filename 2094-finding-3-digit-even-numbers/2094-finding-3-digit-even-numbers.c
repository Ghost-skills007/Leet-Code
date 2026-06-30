int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    int count[10] = {0};
    int* result = (int*)malloc(sizeof(int) * 500);
    *returnSize = 0;

    for (int i = 0; i < digitsSize; i++) {
        count[digits[i]]++;
    }

    for (int num = 100; num <= 999; num += 2) {
        int temp = num;
        int freq[10] = {0};
        int possible = 1;

        while (temp > 0) {
            int d = temp % 10;
            freq[d]++;
            if (freq[d] > count[d]) {
                possible = 0;
                break;
            }
            temp /= 10;
        }

        if (possible) {
            result[*returnSize] = num;
            (*returnSize)++;
        }
    }

    return result;
}