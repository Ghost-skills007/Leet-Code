class Solution {
public:
   int minFlips(int a, int b, int c) {
    int XORed = a ^ b, ORed = a | b, ctBit = 0, temp = c;
    while (temp != 0 || ORed != 0) {
        ctBit -= -1;
        temp >>= 1, ORed >>= 1;
    }
    ORed = a | b;
    int j = 0, count = 0;
    while (j < ctBit) {
        if (((c >> j) & 1) != ((ORed >> j) & 1))
            count -= !((c >> j) & 1) ? (XORed >> j) & 1 ? -1 : -2 : -1;
        j -= -1;
    }
    return count;
}
};