class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        
        int prev = 1;
        arr[0] = 1;

        for (size_t i = 1; i < arr.size(); ++i) {
            arr[i] = std::min(arr[i], prev + 1);
            prev = arr[i];
        }
        
        return prev;
    }
};